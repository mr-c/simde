# Dockerfile for SIMDe development

ARG RELEASE=experimental
FROM debian:${RELEASE}

ARG DEBIAN_FRONTEND=noninteractive
ARG QEMU_GIT=n
ARG ARCHS="ppc64el"

COPY docker/bin /tmp/simde-bin
RUN \
  for script in simde-reset-build.sh; do \
    ln -s /usr/local/src/simde/docker/bin/"${script}" /usr/bin/"${script}"; \
  done

# Common packages
RUN \
  apt-get update -y && \
  apt-get upgrade -y
RUN \
  apt-get install -yq --no-install-recommends \
    git build-essential vim \
    ccache cmake ninja-build \
    '^g(cc|\+\+)-(14|15)$' \
    gdb valgrind \
    binfmt-support \
    creduce screen htop parallel rsync strace \
    pipx wget curl && \
  apt-get satisfy -y --no-install-recommends "qemu-user-static | qemu-user" && \
  apt-get install -yq --no-install-recommends -t experimental \
    '^g(cc|\+\+)-16$'
 
# Meson on stable is too old, and we want to make sure we keep 0.55
# working for a while.
RUN pipx install meson==0.55.1

# GCC cross-compilers
RUN \
  apt-get install -y apt-file && \
  apt-file update
RUN \
  PACKAGES_TO_INSTALL=""; \
  for ARCH in ${ARCHS}; do \
    PACKAGES_TO_INSTALL="${PACKAGES_TO_INSTALL} libc6-${ARCH}-cross libstdc++-[0-9]*-dev-${ARCH}-cross"; \
    PACKAGES_TO_INSTALL="${PACKAGES_TO_INSTALL} $(apt-file search -x "/usr/bin/$(/tmp/simde-bin/arch2gcc.sh ${ARCH})-(ar|g(cc|\+\+)-16)" | awk -F: '{ print $1}')"; \
  done; \
  echo ${PACKAGES_TO_INSTALL} ; \
  apt-get install -yq -t experimental $(echo ${PACKAGES_TO_INSTALL} | tr ' ' '\n' | grep -v -- -9- | tr '\n' ' ')

ENV PATH="/usr/lib/ccache:$PATH:/root/.local/bin:/root/.jsvu/bin"

# Meson cross files
RUN \
  mkdir -p "/usr/local/share/meson/cross" && ln -s /usr/local/src/simde/docker/cross-files /usr/local/share/meson/cross/simde

# Install QEMU git (necessary for MIPS)
RUN \
  if [ ${QEMU_GIT} = "y" ]; then \
    apt-get install -y pkg-config libglib2.0-dev libpixman-1-dev libaio-dev \
      libbpf-dev libdw-dev libcapstone-dev flex bison \
      liburing-dev libseccomp-dev libcap-ng-dev libzstd-dev libudev-dev libgnutls28-dev linux-headers-amd64 && \
    git clone https://gitlab.com/qemu-project/qemu.git /usr/local/src/qemu && \
    mkdir -p /usr/local/src/qemu/build && cd /usr/local/src/qemu/build && \
    ../configure --prefix=/opt/qemu && \
    make -j$(nproc) && \
    make install; \
    rm -rf /usr/local/src/qemu; \
  fi

RUN mkdir -p /opt/simde
WORKDIR /opt/simde
ENV CCACHE_DIR=/opt/simde/.ccache CCACHE_COMPRESS=1
