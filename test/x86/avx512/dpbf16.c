#define SIMDE_TEST_X86_AVX512_INSN dpbf16

#include <test/x86/avx512/test-avx512.h>
#include <simde/x86/avx512/dpbf16.h>

static int
test_simde_mm_dpbf16_ps (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const simde_float32 src[4];
    const simde_float32 a[4];
    const simde_float32 b[4];
    const simde_float32 r[4];
  } test_vec[] = {
    #if !defined(SIMDE_FAST_MATH)
    { { SIMDE_FLOAT32_C(     0.93), SIMDE_FLOAT32_C(   -30.68), SIMDE_FLOAT32_C(     7.59), SIMDE_FLOAT32_C(     4.46) },
      {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(   -27.99),            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(    45.72) },
      { SIMDE_FLOAT32_C(    -2.47),            SIMDE_MATH_NANF,            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(     0.29) },
      {            SIMDE_MATH_NANF,            SIMDE_MATH_NANF,            SIMDE_MATH_NANF,     -SIMDE_MATH_INFINITYF } },
    #endif
    { { SIMDE_FLOAT32_C(    44.06), SIMDE_FLOAT32_C(    39.39), SIMDE_FLOAT32_C(   -16.35), SIMDE_FLOAT32_C(   -41.96) },
      { SIMDE_FLOAT32_C(    25.67), SIMDE_FLOAT32_C(   -10.76), SIMDE_FLOAT32_C(   -35.31), SIMDE_FLOAT32_C(   -34.29) },
      { SIMDE_FLOAT32_C(    24.99), SIMDE_FLOAT32_C(   -33.35), SIMDE_FLOAT32_C(   -42.40), SIMDE_FLOAT32_C(    38.29) },
      {     -SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(7416054272.00), SIMDE_FLOAT32_C(  1472.96), SIMDE_FLOAT32_C( -1352.02) } },
    { { SIMDE_FLOAT32_C(   -14.13), SIMDE_FLOAT32_C(   -21.45), SIMDE_FLOAT32_C(    47.00), SIMDE_FLOAT32_C(    49.00) },
      { SIMDE_FLOAT32_C(    49.48), SIMDE_FLOAT32_C(   -43.57), SIMDE_FLOAT32_C(    -3.78), SIMDE_FLOAT32_C(    46.59) },
      { SIMDE_FLOAT32_C(     5.84), SIMDE_FLOAT32_C(   -44.27), SIMDE_FLOAT32_C(    -9.99), SIMDE_FLOAT32_C(    26.51) },
      {      SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(  1903.43),      SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(  1281.25) } },
    { { SIMDE_FLOAT32_C(   -18.95), SIMDE_FLOAT32_C(    24.25), SIMDE_FLOAT32_C(    11.61), SIMDE_FLOAT32_C(   -10.02) },
      { SIMDE_FLOAT32_C(    36.90), SIMDE_FLOAT32_C(   -27.07), SIMDE_FLOAT32_C(    38.86), SIMDE_FLOAT32_C(   -40.80) },
      { SIMDE_FLOAT32_C(    18.20), SIMDE_FLOAT32_C(   -38.04), SIMDE_FLOAT32_C(   -18.22), SIMDE_FLOAT32_C(   -33.36) },
      { SIMDE_FLOAT32_C(   647.14), SIMDE_FLOAT32_C(  1050.25), SIMDE_FLOAT32_C(-29032169801320738206934261301248.00), SIMDE_FLOAT32_C(16922581844619299913728.00) } },
    { { SIMDE_FLOAT32_C(    47.73), SIMDE_FLOAT32_C(   -29.20), SIMDE_FLOAT32_C(   -45.25), SIMDE_FLOAT32_C(   -23.06) },
      { SIMDE_FLOAT32_C(   -16.02), SIMDE_FLOAT32_C(    43.85), SIMDE_FLOAT32_C(   -37.64), SIMDE_FLOAT32_C(    31.51) },
      { SIMDE_FLOAT32_C(   -46.48), SIMDE_FLOAT32_C(    24.74), SIMDE_FLOAT32_C(   -18.20), SIMDE_FLOAT32_C(    29.19) },
      { SIMDE_FLOAT32_C(-8782671249408.00),     -SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(   634.44), SIMDE_FLOAT32_C(   894.38) } },
    { { SIMDE_FLOAT32_C(   -30.00), SIMDE_FLOAT32_C(    -3.97), SIMDE_FLOAT32_C(    -6.96), SIMDE_FLOAT32_C(    -7.87) },
      { SIMDE_FLOAT32_C(   -36.02), SIMDE_FLOAT32_C(    -3.52), SIMDE_FLOAT32_C(    44.90), SIMDE_FLOAT32_C(    38.96) },
      { SIMDE_FLOAT32_C(    13.13), SIMDE_FLOAT32_C(   -47.50), SIMDE_FLOAT32_C(    27.25), SIMDE_FLOAT32_C(    12.61) },
      { SIMDE_FLOAT32_C(  -502.50), SIMDE_FLOAT32_C(   163.02), SIMDE_FLOAT32_C(  1212.48), SIMDE_FLOAT32_C(10848881231265792.00) } },
    { { SIMDE_FLOAT32_C(    26.18), SIMDE_FLOAT32_C(    18.34), SIMDE_FLOAT32_C(   -17.54), SIMDE_FLOAT32_C(   -31.71) },
      { SIMDE_FLOAT32_C(   -41.07), SIMDE_FLOAT32_C(   -26.52), SIMDE_FLOAT32_C(     9.19), SIMDE_FLOAT32_C(    14.77) },
      { SIMDE_FLOAT32_C(   -20.79), SIMDE_FLOAT32_C(    49.20), SIMDE_FLOAT32_C(    -8.72), SIMDE_FLOAT32_C(   -33.90) },
      { SIMDE_FLOAT32_C(11287586370748416.00), SIMDE_FLOAT32_C( -1280.16), SIMDE_FLOAT32_C(   -97.36), SIMDE_FLOAT32_C(  -529.52) } },
    { { SIMDE_FLOAT32_C(   -24.57), SIMDE_FLOAT32_C(   -10.57), SIMDE_FLOAT32_C(    44.37), SIMDE_FLOAT32_C(    26.36) },
      { SIMDE_FLOAT32_C(   -27.87), SIMDE_FLOAT32_C(   -19.86), SIMDE_FLOAT32_C(   -24.70), SIMDE_FLOAT32_C(    40.33) },
      { SIMDE_FLOAT32_C(    -7.89), SIMDE_FLOAT32_C(     7.09), SIMDE_FLOAT32_C(   -43.03), SIMDE_FLOAT32_C(    26.08) },
      {     -SIMDE_MATH_INFINITYF,      SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(  1103.24), SIMDE_FLOAT32_C(  1072.86) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m128 tmp, src, r;
    simde__m128bh a;
    simde__m128bh b;

    src = simde_mm_loadu_ps(test_vec[i].src);

    tmp = simde_mm_loadu_ps(test_vec[i].a);
    simde_memcpy(&a, &tmp, sizeof(tmp));

    tmp = simde_mm_loadu_ps(test_vec[i].b);
    simde_memcpy(&b, &tmp, sizeof(tmp));

    r = simde_mm_dpbf16_ps(src, a, b);
    simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[i].r), 1);
  }

  return 0;
#else
  fputc('\n', stdout);
  simde_float32 values[8 * 2 * sizeof(simde__m128)];
  simde_test_x86_random_f32x4_full(8, 2, values, -50.0f, 50.0f, SIMDE_TEST_VEC_FLOAT_NAN);

  for (size_t i = 0 ; i < 8 ; i++) {
    simde__m128 src = simde_test_x86_random_f32x4(SIMDE_FLOAT32_C(-50.0), SIMDE_FLOAT32_C(50.0));
    simde__m128bh a = HEDLEY_REINTERPRET_CAST(simde__m128bh, simde_test_x86_random_extract_f32x4(i, 2, 0, values));
    simde__m128bh b = HEDLEY_REINTERPRET_CAST(simde__m128bh, simde_test_x86_random_extract_f32x4(i, 2, 1, values));
    simde__m128 r = simde_mm_dpbf16_ps(src, a, b);

    simde_test_x86_write_f32x4(2, src, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_f32x4(2, HEDLEY_REINTERPRET_CAST(simde__m128, a), SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_f32x4(2, HEDLEY_REINTERPRET_CAST(simde__m128, b), SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_f32x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm_mask_dpbf16_ps (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const simde_float32 src[4];
    const simde__mmask8 k;
    const simde_float32 a[4];
    const simde_float32 b[4];
    const simde_float32 r[4];
  } test_vec[] = {
    #if !defined(SIMDE_FAST_MATH)
    { { SIMDE_FLOAT32_C(    35.52), SIMDE_FLOAT32_C(   -15.16), SIMDE_FLOAT32_C(    12.96), SIMDE_FLOAT32_C(   -37.51) },
      UINT8_C( 28),
      {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(    37.95),            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(   -46.79) },
      { SIMDE_FLOAT32_C(    12.78),            SIMDE_MATH_NANF,            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(   -34.41) },
      { SIMDE_FLOAT32_C(    35.52), SIMDE_FLOAT32_C(   -15.16),            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(  1563.68) } },
    #endif
    { { SIMDE_FLOAT32_C(    19.58), SIMDE_FLOAT32_C(    34.74), SIMDE_FLOAT32_C(    11.92), SIMDE_FLOAT32_C(   -27.97) },
      UINT8_C( 43),
      { SIMDE_FLOAT32_C(    -4.73), SIMDE_FLOAT32_C(   -44.27), SIMDE_FLOAT32_C(    -4.16), SIMDE_FLOAT32_C(     5.47) },
      { SIMDE_FLOAT32_C(    12.69), SIMDE_FLOAT32_C(    46.62), SIMDE_FLOAT32_C(    24.70), SIMDE_FLOAT32_C(   -22.72) },
      { SIMDE_FLOAT32_C(   -40.29), SIMDE_FLOAT32_C(7402289152.00), SIMDE_FLOAT32_C(    11.92), SIMDE_FLOAT32_C(  -151.70) } },
    { { SIMDE_FLOAT32_C(    -8.98), SIMDE_FLOAT32_C(    21.11), SIMDE_FLOAT32_C(   -35.13), SIMDE_FLOAT32_C(    -2.61) },
      UINT8_C( 44),
      { SIMDE_FLOAT32_C(   -47.49), SIMDE_FLOAT32_C(   -43.31), SIMDE_FLOAT32_C(    48.10), SIMDE_FLOAT32_C(    48.31) },
      { SIMDE_FLOAT32_C(   -33.22), SIMDE_FLOAT32_C(   -45.96), SIMDE_FLOAT32_C(    12.04), SIMDE_FLOAT32_C(    -9.66) },
      { SIMDE_FLOAT32_C(    -8.98), SIMDE_FLOAT32_C(    21.11), SIMDE_FLOAT32_C(-6329059.00), SIMDE_FLOAT32_C(  -467.02) } },
    { { SIMDE_FLOAT32_C(    14.51), SIMDE_FLOAT32_C(   -11.26), SIMDE_FLOAT32_C(    13.15), SIMDE_FLOAT32_C(    34.22) },
      UINT8_C( 70),
      { SIMDE_FLOAT32_C(   -33.59), SIMDE_FLOAT32_C(     2.45), SIMDE_FLOAT32_C(   -22.28), SIMDE_FLOAT32_C(    29.10) },
      { SIMDE_FLOAT32_C(    -0.93), SIMDE_FLOAT32_C(   -47.58), SIMDE_FLOAT32_C(   -43.63), SIMDE_FLOAT32_C(     1.58) },
      { SIMDE_FLOAT32_C(    14.51), SIMDE_FLOAT32_C(-13617759373261537280.00), SIMDE_FLOAT32_C(   981.03), SIMDE_FLOAT32_C(    34.22) } },
    { { SIMDE_FLOAT32_C(   -14.91), SIMDE_FLOAT32_C(    19.73), SIMDE_FLOAT32_C(   -18.66), SIMDE_FLOAT32_C(    48.05) },
      UINT8_C(227),
      { SIMDE_FLOAT32_C(   -40.90), SIMDE_FLOAT32_C(   -45.52), SIMDE_FLOAT32_C(    -0.11), SIMDE_FLOAT32_C(   -24.11) },
      { SIMDE_FLOAT32_C(   -41.49), SIMDE_FLOAT32_C(   -38.07), SIMDE_FLOAT32_C(    16.22), SIMDE_FLOAT32_C(    -7.83) },
      { SIMDE_FLOAT32_C(7872185856.00), SIMDE_FLOAT32_C(  1748.73), SIMDE_FLOAT32_C(   -18.66), SIMDE_FLOAT32_C(    48.05) } },
    { { SIMDE_FLOAT32_C(    26.85), SIMDE_FLOAT32_C(    17.63), SIMDE_FLOAT32_C(    16.96), SIMDE_FLOAT32_C(   -11.23) },
      UINT8_C( 73),
      { SIMDE_FLOAT32_C(    20.34), SIMDE_FLOAT32_C(   -46.62), SIMDE_FLOAT32_C(    11.95), SIMDE_FLOAT32_C(    33.90) },
      { SIMDE_FLOAT32_C(    -6.32), SIMDE_FLOAT32_C(   -30.29), SIMDE_FLOAT32_C(     7.76), SIMDE_FLOAT32_C(    21.94) },
      { SIMDE_FLOAT32_C(  -100.98), SIMDE_FLOAT32_C(    17.63), SIMDE_FLOAT32_C(    16.96), SIMDE_FLOAT32_C(   727.05) } },
    { { SIMDE_FLOAT32_C(   -36.14), SIMDE_FLOAT32_C(    33.15), SIMDE_FLOAT32_C(   -46.67), SIMDE_FLOAT32_C(    30.56) },
      UINT8_C( 43),
      { SIMDE_FLOAT32_C(    16.14), SIMDE_FLOAT32_C(     2.20), SIMDE_FLOAT32_C(    42.34), SIMDE_FLOAT32_C(    45.79) },
      { SIMDE_FLOAT32_C(    17.91), SIMDE_FLOAT32_C(    39.28), SIMDE_FLOAT32_C(   -38.32), SIMDE_FLOAT32_C(    -5.20) },
      { SIMDE_FLOAT32_C(   252.09), SIMDE_FLOAT32_C(   119.01), SIMDE_FLOAT32_C(   -46.67), SIMDE_FLOAT32_C(7416053760.00) } },
    { { SIMDE_FLOAT32_C(    42.26), SIMDE_FLOAT32_C(    -4.90), SIMDE_FLOAT32_C(   -10.91), SIMDE_FLOAT32_C(   -34.04) },
      UINT8_C(193),
      { SIMDE_FLOAT32_C(     0.12), SIMDE_FLOAT32_C(    29.82), SIMDE_FLOAT32_C(   -42.37), SIMDE_FLOAT32_C(    31.08) },
      { SIMDE_FLOAT32_C(   -47.45), SIMDE_FLOAT32_C(   -18.97), SIMDE_FLOAT32_C(   -46.05), SIMDE_FLOAT32_C(     7.17) },
      { SIMDE_FLOAT32_C(7684751360.00), SIMDE_FLOAT32_C(    -4.90), SIMDE_FLOAT32_C(   -10.91), SIMDE_FLOAT32_C(   -34.04) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m128 tmp, src, r;
    simde__m128bh a, b;

    src = simde_mm_loadu_ps(test_vec[i].src);

    tmp = simde_mm_loadu_ps(test_vec[i].a);
    simde_memcpy(&a, &tmp, sizeof(tmp));

    tmp = simde_mm_loadu_ps(test_vec[i].b);
    simde_memcpy(&b, &tmp, sizeof(tmp));

    r = simde_mm_mask_dpbf16_ps(src, test_vec[i].k, a, b);
    simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[i].r), 1);
  }

  return 0;
#else
  fputc('\n', stdout);
  simde_float32 values[8 * 2 * sizeof(simde__m128)];
  simde_test_x86_random_f32x4_full(8, 2, values, -50.0f, 50.0f, SIMDE_TEST_VEC_FLOAT_NAN);

  for (size_t i = 0 ; i < 8 ; i++) {
    simde__m128 src = simde_test_x86_random_f32x4(SIMDE_FLOAT32_C(-50.0), SIMDE_FLOAT32_C(50.0));
    simde__mmask8 k = simde_test_x86_random_mmask8();
    simde__m128bh a = HEDLEY_REINTERPRET_CAST(simde__m128bh, simde_test_x86_random_extract_f32x4(i, 2, 0, values));
    simde__m128bh b = HEDLEY_REINTERPRET_CAST(simde__m128bh, simde_test_x86_random_extract_f32x4(i, 2, 1, values));
    simde__m128 r = simde_mm_mask_dpbf16_ps(src, k, a, b);

    simde_test_x86_write_f32x4(2, src, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_mmask8(2, k, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_f32x4(2, HEDLEY_REINTERPRET_CAST(simde__m128, a), SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_f32x4(2, HEDLEY_REINTERPRET_CAST(simde__m128, b), SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_f32x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm_maskz_dpbf16_ps (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const simde__mmask8 k;
    const simde_float32 src[4];
    const simde_float32 a[4];
    const simde_float32 b[4];
    const simde_float32 r[4];
  } test_vec[] = {
    #if !defined(SIMDE_FAST_MATH)
    { UINT8_C(199),
      { SIMDE_FLOAT32_C(   -22.83), SIMDE_FLOAT32_C(    28.42), SIMDE_FLOAT32_C(    20.82), SIMDE_FLOAT32_C(   -21.24) },
      {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(    29.78),            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(    44.29) },
      { SIMDE_FLOAT32_C(   -22.83),            SIMDE_MATH_NANF,            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(    29.04) },
      {            SIMDE_MATH_NANF,            SIMDE_MATH_NANF,            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(     0.00) } },
    #endif
    { UINT8_C(235),
      { SIMDE_FLOAT32_C(   -21.64), SIMDE_FLOAT32_C(    48.49), SIMDE_FLOAT32_C(    -5.03), SIMDE_FLOAT32_C(   -23.56) },
      { SIMDE_FLOAT32_C(     6.04), SIMDE_FLOAT32_C(    18.13), SIMDE_FLOAT32_C(   -10.58), SIMDE_FLOAT32_C(    -9.46) },
      { SIMDE_FLOAT32_C(    34.22), SIMDE_FLOAT32_C(    -8.03), SIMDE_FLOAT32_C(    45.38), SIMDE_FLOAT32_C(   -46.31) },
      { SIMDE_FLOAT32_C(-20542294200482956679577600.00), SIMDE_FLOAT32_C(  5219.12), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(11195502271922176.00) } },
    { UINT8_C(228),
      { SIMDE_FLOAT32_C(    39.92), SIMDE_FLOAT32_C(   -30.09), SIMDE_FLOAT32_C(   -39.94), SIMDE_FLOAT32_C(    -8.65) },
      { SIMDE_FLOAT32_C(   -43.52), SIMDE_FLOAT32_C(   -15.88), SIMDE_FLOAT32_C(    16.84), SIMDE_FLOAT32_C(    40.69) },
      { SIMDE_FLOAT32_C(   -19.38), SIMDE_FLOAT32_C(   -48.07), SIMDE_FLOAT32_C(    10.42), SIMDE_FLOAT32_C(    11.96) },
      { SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(   133.84), SIMDE_FLOAT32_C(     0.00) } },
    { UINT8_C(254),
      { SIMDE_FLOAT32_C(   -15.47), SIMDE_FLOAT32_C(    33.47), SIMDE_FLOAT32_C(   -44.29), SIMDE_FLOAT32_C(    10.93) },
      { SIMDE_FLOAT32_C(    49.98), SIMDE_FLOAT32_C(    -7.35), SIMDE_FLOAT32_C(   -11.19), SIMDE_FLOAT32_C(    17.61) },
      { SIMDE_FLOAT32_C(   -40.39), SIMDE_FLOAT32_C(    27.57), SIMDE_FLOAT32_C(     7.27), SIMDE_FLOAT32_C(    39.03) },
      { SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(  -168.48), SIMDE_FLOAT32_C(  -125.40), SIMDE_FLOAT32_C(   688.94) } },
    { UINT8_C( 48),
      { SIMDE_FLOAT32_C(    36.02), SIMDE_FLOAT32_C(   -28.60), SIMDE_FLOAT32_C(   -17.43), SIMDE_FLOAT32_C(   -20.14) },
      { SIMDE_FLOAT32_C(    19.73), SIMDE_FLOAT32_C(   -47.02), SIMDE_FLOAT32_C(    48.09), SIMDE_FLOAT32_C(     3.94) },
      { SIMDE_FLOAT32_C(    -5.05), SIMDE_FLOAT32_C(    43.47), SIMDE_FLOAT32_C(     7.63), SIMDE_FLOAT32_C(     1.43) },
      { SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00) } },
    { UINT8_C(  9),
      { SIMDE_FLOAT32_C(   -48.11), SIMDE_FLOAT32_C(     7.03), SIMDE_FLOAT32_C(    43.72), SIMDE_FLOAT32_C(    22.70) },
      { SIMDE_FLOAT32_C(   -22.41), SIMDE_FLOAT32_C(   -25.53), SIMDE_FLOAT32_C(    -7.88), SIMDE_FLOAT32_C(     8.21) },
      { SIMDE_FLOAT32_C(   -23.60), SIMDE_FLOAT32_C(   -47.46), SIMDE_FLOAT32_C(   -29.83), SIMDE_FLOAT32_C(   -23.62) },
      { SIMDE_FLOAT32_C(-9575092715520.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00),     -SIMDE_MATH_INFINITYF } },
    { UINT8_C(102),
      { SIMDE_FLOAT32_C(   -14.30), SIMDE_FLOAT32_C(   -48.94), SIMDE_FLOAT32_C(    34.28), SIMDE_FLOAT32_C(    30.67) },
      { SIMDE_FLOAT32_C(    -4.80), SIMDE_FLOAT32_C(     8.97), SIMDE_FLOAT32_C(    43.99), SIMDE_FLOAT32_C(     4.81) },
      { SIMDE_FLOAT32_C(   -13.46), SIMDE_FLOAT32_C(     1.27), SIMDE_FLOAT32_C(    -6.16), SIMDE_FLOAT32_C(    43.90) },
      { SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(   -37.63), SIMDE_FLOAT32_C(-9631464161280.00), SIMDE_FLOAT32_C(     0.00) } },
    { UINT8_C( 73),
      { SIMDE_FLOAT32_C(   -30.20), SIMDE_FLOAT32_C(   -38.70), SIMDE_FLOAT32_C(    -2.33), SIMDE_FLOAT32_C(   -12.17) },
      { SIMDE_FLOAT32_C(    -8.28), SIMDE_FLOAT32_C(   -37.76), SIMDE_FLOAT32_C(     7.19), SIMDE_FLOAT32_C(     5.90) },
      { SIMDE_FLOAT32_C(    37.14), SIMDE_FLOAT32_C(   -26.21), SIMDE_FLOAT32_C(   -32.69), SIMDE_FLOAT32_C(   -28.12) },
      { SIMDE_FLOAT32_C(-6336335.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00),      SIMDE_MATH_INFINITYF } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m128 tmp, src, r;
    simde__m128bh a, b;

    src = simde_mm_loadu_ps(test_vec[i].src);

    tmp = simde_mm_loadu_ps(test_vec[i].a);
    simde_memcpy(&a, &tmp, sizeof(tmp));

    tmp = simde_mm_loadu_ps(test_vec[i].b);
    simde_memcpy(&b, &tmp, sizeof(tmp));

    r = simde_mm_maskz_dpbf16_ps(test_vec[i].k, src, a, b);
    simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[i].r), 1);
  }

  return 0;
#else
  fputc('\n', stdout);
  simde_float32 values[8 * 2 * sizeof(simde__m128)];
  simde_test_x86_random_f32x4_full(8, 2, values, -50.0f, 50.0f, SIMDE_TEST_VEC_FLOAT_NAN);

  for (size_t i = 0 ; i < 8 ; i++) {
    simde__mmask8 k = simde_test_x86_random_mmask8();
    simde__m128 src = simde_test_x86_random_f32x4(SIMDE_FLOAT32_C(-50.0), SIMDE_FLOAT32_C(50.0));
    simde__m128bh a = HEDLEY_REINTERPRET_CAST(simde__m128bh, simde_test_x86_random_extract_f32x4(i, 2, 0, values));
    simde__m128bh b = HEDLEY_REINTERPRET_CAST(simde__m128bh, simde_test_x86_random_extract_f32x4(i, 2, 1, values));
    simde__m128 r = simde_mm_maskz_dpbf16_ps(k, src, a, b);

    simde_test_x86_write_mmask8(2, k, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_f32x4(2, src, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_f32x4(2, HEDLEY_REINTERPRET_CAST(simde__m128, a), SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_f32x4(2, HEDLEY_REINTERPRET_CAST(simde__m128, b), SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_f32x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm256_dpbf16_ps (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const simde_float32 src[8];
    const simde_float32 a[8];
    const simde_float32 b[8];
    const simde_float32 r[8];
  } test_vec[] = {
    #if !defined(SIMDE_FAST_MATH)
    { { SIMDE_FLOAT32_C(   -43.55), SIMDE_FLOAT32_C(   -40.45), SIMDE_FLOAT32_C(    32.76), SIMDE_FLOAT32_C(   -28.04),
        SIMDE_FLOAT32_C(   -49.60), SIMDE_FLOAT32_C(    -3.34), SIMDE_FLOAT32_C(   -24.54), SIMDE_FLOAT32_C(    -4.35) },
      {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(    21.20),            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(   -15.30),
        SIMDE_FLOAT32_C(   -19.91), SIMDE_FLOAT32_C(   -23.31), SIMDE_FLOAT32_C(     4.99), SIMDE_FLOAT32_C(   -16.82) },
      { SIMDE_FLOAT32_C(   -40.48),            SIMDE_MATH_NANF,            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(   -43.54),
        SIMDE_FLOAT32_C(    42.85), SIMDE_FLOAT32_C(   -44.25), SIMDE_FLOAT32_C(   -25.14), SIMDE_FLOAT32_C(    17.55) },
      {            SIMDE_MATH_NANF,            SIMDE_MATH_NANF,            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(   635.34),
        SIMDE_FLOAT32_C(24190605650488729785870581760.00), SIMDE_FLOAT32_C(  1025.47), SIMDE_FLOAT32_C(  -149.38), SIMDE_FLOAT32_C(  -297.48) } },
    #endif
    { { SIMDE_FLOAT32_C(    44.44), SIMDE_FLOAT32_C(    41.32), SIMDE_FLOAT32_C(    38.89), SIMDE_FLOAT32_C(   -14.30),
        SIMDE_FLOAT32_C(     3.18), SIMDE_FLOAT32_C(    24.09), SIMDE_FLOAT32_C(    48.74), SIMDE_FLOAT32_C(     0.39) },
      { SIMDE_FLOAT32_C(     9.27), SIMDE_FLOAT32_C(   -49.63), SIMDE_FLOAT32_C(   -31.31), SIMDE_FLOAT32_C(   -44.30),
        SIMDE_FLOAT32_C(    32.50), SIMDE_FLOAT32_C(   -18.32), SIMDE_FLOAT32_C(    39.56), SIMDE_FLOAT32_C(   -42.25) },
      { SIMDE_FLOAT32_C(     8.28), SIMDE_FLOAT32_C(    23.80), SIMDE_FLOAT32_C(    48.27), SIMDE_FLOAT32_C(    -1.67),
        SIMDE_FLOAT32_C(   -22.88), SIMDE_FLOAT32_C(    19.98), SIMDE_FLOAT32_C(    27.98), SIMDE_FLOAT32_C(    29.46) },
      {      SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C( -1134.31), SIMDE_FLOAT32_C(7402289664.00), SIMDE_FLOAT32_C(    59.33),
        SIMDE_FLOAT32_C(  -740.26), SIMDE_FLOAT32_C(  -338.63), SIMDE_FLOAT32_C(-8927626395648.00), SIMDE_FLOAT32_C( -1240.70) } },
    { { SIMDE_FLOAT32_C(   -22.28), SIMDE_FLOAT32_C(    -6.46), SIMDE_FLOAT32_C(   -38.16), SIMDE_FLOAT32_C(    34.00),
        SIMDE_FLOAT32_C(    38.34), SIMDE_FLOAT32_C(    -9.77), SIMDE_FLOAT32_C(    25.42), SIMDE_FLOAT32_C(    49.76) },
      { SIMDE_FLOAT32_C(    -8.82), SIMDE_FLOAT32_C(    26.07), SIMDE_FLOAT32_C(   -35.84), SIMDE_FLOAT32_C(    21.26),
        SIMDE_FLOAT32_C(   -47.24), SIMDE_FLOAT32_C(    19.15), SIMDE_FLOAT32_C(   -45.56), SIMDE_FLOAT32_C(   -37.72) },
      { SIMDE_FLOAT32_C(    -0.79), SIMDE_FLOAT32_C(    18.63), SIMDE_FLOAT32_C(   -31.27), SIMDE_FLOAT32_C(    -7.94),
        SIMDE_FLOAT32_C(    24.38), SIMDE_FLOAT32_C(    -6.40), SIMDE_FLOAT32_C(   -40.39), SIMDE_FLOAT32_C(   -16.36) },
      { SIMDE_FLOAT32_C(   -15.33), SIMDE_FLOAT32_C(   477.79), SIMDE_FLOAT32_C(  6275.78), SIMDE_FLOAT32_C(  -134.67),
        SIMDE_FLOAT32_C( -1111.78), SIMDE_FLOAT32_C(  -136.17), SIMDE_FLOAT32_C(  1856.80),      SIMDE_MATH_INFINITYF } },
    { { SIMDE_FLOAT32_C(    15.37), SIMDE_FLOAT32_C(   -45.56), SIMDE_FLOAT32_C(   -27.67), SIMDE_FLOAT32_C(    46.56),
        SIMDE_FLOAT32_C(   -35.28), SIMDE_FLOAT32_C(    26.70), SIMDE_FLOAT32_C(     7.23), SIMDE_FLOAT32_C(   -28.83) },
      { SIMDE_FLOAT32_C(    -6.04), SIMDE_FLOAT32_C(   -21.70), SIMDE_FLOAT32_C(   -10.66), SIMDE_FLOAT32_C(   -23.53),
        SIMDE_FLOAT32_C(     9.98), SIMDE_FLOAT32_C(   -21.10), SIMDE_FLOAT32_C(   -15.78), SIMDE_FLOAT32_C(   -31.74) },
      { SIMDE_FLOAT32_C(   -47.30), SIMDE_FLOAT32_C(   -17.51), SIMDE_FLOAT32_C(    16.59), SIMDE_FLOAT32_C(   -20.18),
        SIMDE_FLOAT32_C(   -47.53), SIMDE_FLOAT32_C(    -5.44), SIMDE_FLOAT32_C(   -40.72), SIMDE_FLOAT32_C(    -6.35) },
      { SIMDE_FLOAT32_C(   300.35), SIMDE_FLOAT32_C(   332.88), SIMDE_FLOAT32_C(  -202.98), SIMDE_FLOAT32_C(23890792047224301750543450112.00),
        SIMDE_FLOAT32_C(  -507.31), SIMDE_FLOAT32_C(   140.89),     -SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(-13402149541101174784.00) } },
    { { SIMDE_FLOAT32_C(    36.26), SIMDE_FLOAT32_C(   -10.01), SIMDE_FLOAT32_C(    -6.87), SIMDE_FLOAT32_C(    36.66),
        SIMDE_FLOAT32_C(    36.66), SIMDE_FLOAT32_C(    18.59), SIMDE_FLOAT32_C(   -17.70), SIMDE_FLOAT32_C(    31.10) },
      { SIMDE_FLOAT32_C(   -29.37), SIMDE_FLOAT32_C(   -26.55), SIMDE_FLOAT32_C(   -35.09), SIMDE_FLOAT32_C(   -26.61),
        SIMDE_FLOAT32_C(    42.60), SIMDE_FLOAT32_C(   -30.65), SIMDE_FLOAT32_C(   -14.33), SIMDE_FLOAT32_C(    -8.19) },
      { SIMDE_FLOAT32_C(    37.98), SIMDE_FLOAT32_C(     4.40), SIMDE_FLOAT32_C(    33.88), SIMDE_FLOAT32_C(    12.36),
        SIMDE_FLOAT32_C(    48.00), SIMDE_FLOAT32_C(    43.48), SIMDE_FLOAT32_C(    46.00), SIMDE_FLOAT32_C(    -8.04) },
      {      SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(-29184436426152839980746853580800.00), SIMDE_FLOAT32_C( -1188.12), SIMDE_FLOAT32_C(16486777515877911756800.00),
        SIMDE_FLOAT32_C(  2076.66), SIMDE_FLOAT32_C(-13402149541101174784.00), SIMDE_FLOAT32_C(  -676.08), SIMDE_FLOAT32_C(    96.60) } },
    { { SIMDE_FLOAT32_C(     9.08), SIMDE_FLOAT32_C(    25.33), SIMDE_FLOAT32_C(   -42.99), SIMDE_FLOAT32_C(    -2.58),
        SIMDE_FLOAT32_C(   -34.44), SIMDE_FLOAT32_C(    32.43), SIMDE_FLOAT32_C(    -2.82), SIMDE_FLOAT32_C(    30.93) },
      { SIMDE_FLOAT32_C(   -20.51), SIMDE_FLOAT32_C(    46.17), SIMDE_FLOAT32_C(     5.18), SIMDE_FLOAT32_C(   -27.91),
        SIMDE_FLOAT32_C(   -34.48), SIMDE_FLOAT32_C(    40.85), SIMDE_FLOAT32_C(    13.90), SIMDE_FLOAT32_C(   -46.50) },
      { SIMDE_FLOAT32_C(    -4.75), SIMDE_FLOAT32_C(    -2.22), SIMDE_FLOAT32_C(    15.86), SIMDE_FLOAT32_C(    -6.76),
        SIMDE_FLOAT32_C(    -8.74), SIMDE_FLOAT32_C(    11.86), SIMDE_FLOAT32_C(    35.20), SIMDE_FLOAT32_C(    13.04) },
      { SIMDE_FLOAT32_C(   106.46), SIMDE_FLOAT32_C(   -76.73), SIMDE_FLOAT32_C(  5150.79), SIMDE_FLOAT32_C(11287586370748416.00),
             SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(-19414829202697828884807680.00), SIMDE_FLOAT32_C(-29184436426152839980746853580800.00), SIMDE_FLOAT32_C(  -573.57) } },
    { { SIMDE_FLOAT32_C(   -22.82), SIMDE_FLOAT32_C(   -13.42), SIMDE_FLOAT32_C(   -38.50), SIMDE_FLOAT32_C(    -3.20),
        SIMDE_FLOAT32_C(    -8.82), SIMDE_FLOAT32_C(    17.53), SIMDE_FLOAT32_C(    49.52), SIMDE_FLOAT32_C(     1.94) },
      { SIMDE_FLOAT32_C(   -41.60), SIMDE_FLOAT32_C(     7.42), SIMDE_FLOAT32_C(    27.15), SIMDE_FLOAT32_C(    16.02),
        SIMDE_FLOAT32_C(    22.15), SIMDE_FLOAT32_C(    38.29), SIMDE_FLOAT32_C(   -13.83), SIMDE_FLOAT32_C(    45.19) },
      { SIMDE_FLOAT32_C(    47.35), SIMDE_FLOAT32_C(   -42.76), SIMDE_FLOAT32_C(    48.65), SIMDE_FLOAT32_C(    -6.98),
        SIMDE_FLOAT32_C(   -44.00), SIMDE_FLOAT32_C(    41.52), SIMDE_FLOAT32_C(   -16.70), SIMDE_FLOAT32_C(   -45.18) },
      {      SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(  -330.03), SIMDE_FLOAT32_C(  1277.06), SIMDE_FLOAT32_C(  5082.05),
        SIMDE_FLOAT32_C(  -982.32), SIMDE_FLOAT32_C(  1604.91), SIMDE_FLOAT32_C(   279.15), SIMDE_FLOAT32_C( -2023.06) } },
    { { SIMDE_FLOAT32_C(    45.15), SIMDE_FLOAT32_C(     7.49), SIMDE_FLOAT32_C(     7.14), SIMDE_FLOAT32_C(   -19.46),
        SIMDE_FLOAT32_C(   -34.09), SIMDE_FLOAT32_C(     4.14), SIMDE_FLOAT32_C(    30.94), SIMDE_FLOAT32_C(    23.42) },
      { SIMDE_FLOAT32_C(     5.07), SIMDE_FLOAT32_C(    37.87), SIMDE_FLOAT32_C(   -32.67), SIMDE_FLOAT32_C(   -13.70),
        SIMDE_FLOAT32_C(   -39.25), SIMDE_FLOAT32_C(    41.58), SIMDE_FLOAT32_C(     0.04), SIMDE_FLOAT32_C(    43.83) },
      { SIMDE_FLOAT32_C(     1.07), SIMDE_FLOAT32_C(   -28.76), SIMDE_FLOAT32_C(    33.36), SIMDE_FLOAT32_C(    39.77),
        SIMDE_FLOAT32_C(    47.18), SIMDE_FLOAT32_C(    25.69), SIMDE_FLOAT32_C(   -20.99), SIMDE_FLOAT32_C(   -44.42) },
      { SIMDE_FLOAT32_C(-29088496073108223009442171453440.00), SIMDE_FLOAT32_C(7402290176.00), SIMDE_FLOAT32_C(-13663921269442084864.00), SIMDE_FLOAT32_C(  -563.54),
        SIMDE_FLOAT32_C( -1878.84), SIMDE_FLOAT32_C(  1067.58),      SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C( -1916.78) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m256 tmp, src, r;
    simde__m256bh a, b;

    src = simde_mm256_loadu_ps(test_vec[i].src);

    tmp = simde_mm256_loadu_ps(test_vec[i].a);
    simde_memcpy(&a, &tmp, sizeof(tmp));

    tmp = simde_mm256_loadu_ps(test_vec[i].b);
    simde_memcpy(&b, &tmp, sizeof(tmp));

    r = simde_mm256_dpbf16_ps(src, a, b);
    simde_test_x86_assert_equal_f32x8(r, simde_mm256_loadu_ps(test_vec[i].r), 1);
  }

  return 0;
#else
  fputc('\n', stdout);
  simde_float32 values[8 * 2 * sizeof(simde__m256)];
  simde_test_x86_random_f32x8_full(8, 2, values, -50.0f, 50.0f, SIMDE_TEST_VEC_FLOAT_NAN);

  for (size_t i = 0 ; i < 8 ; i++) {
    simde__m256 src = simde_test_x86_random_f32x8(SIMDE_FLOAT32_C(-50.0), SIMDE_FLOAT32_C(50.0));
    simde__m256bh a = HEDLEY_REINTERPRET_CAST(simde__m256bh, simde_test_x86_random_extract_f32x8(i, 2, 0, values));
    simde__m256bh b = HEDLEY_REINTERPRET_CAST(simde__m256bh, simde_test_x86_random_extract_f32x8(i, 2, 1, values));
    simde__m256 r = simde_mm256_dpbf16_ps(src, a, b);

    simde_test_x86_write_f32x8(2, src, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_f32x8(2, HEDLEY_REINTERPRET_CAST(simde__m256, a), SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_f32x8(2, HEDLEY_REINTERPRET_CAST(simde__m256, b), SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_f32x8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm256_mask_dpbf16_ps (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const simde_float32 src[8];
    const simde__mmask8 k;
    const simde_float32 a[8];
    const simde_float32 b[8];
    const simde_float32 r[8];
  } test_vec[] = {
    { { SIMDE_FLOAT32_C(    18.56), SIMDE_FLOAT32_C(    -7.58), SIMDE_FLOAT32_C(   -43.70), SIMDE_FLOAT32_C(   -16.96),
        SIMDE_FLOAT32_C(   -40.14), SIMDE_FLOAT32_C(     4.59), SIMDE_FLOAT32_C(     1.18), SIMDE_FLOAT32_C(     0.97) },
      UINT8_C(211),
      { SIMDE_FLOAT32_C(   -47.64), SIMDE_FLOAT32_C(    17.81), SIMDE_FLOAT32_C(    46.74), SIMDE_FLOAT32_C(    24.20),
        SIMDE_FLOAT32_C(     9.47), SIMDE_FLOAT32_C(   -29.52), SIMDE_FLOAT32_C(   -32.75), SIMDE_FLOAT32_C(   -45.08) },
      { SIMDE_FLOAT32_C(   -42.94), SIMDE_FLOAT32_C(    34.02), SIMDE_FLOAT32_C(   -28.54), SIMDE_FLOAT32_C(     7.11),
        SIMDE_FLOAT32_C(    31.91), SIMDE_FLOAT32_C(   -43.84), SIMDE_FLOAT32_C(   -31.77), SIMDE_FLOAT32_C(    27.44) },
      { SIMDE_FLOAT32_C(  2049.19), SIMDE_FLOAT32_C(7402291712.00), SIMDE_FLOAT32_C(   -43.70), SIMDE_FLOAT32_C(   -16.96),
        SIMDE_FLOAT32_C(   260.68), SIMDE_FLOAT32_C(     4.59), SIMDE_FLOAT32_C(  1040.99), SIMDE_FLOAT32_C( -1230.91) } },
    { { SIMDE_FLOAT32_C(    44.89), SIMDE_FLOAT32_C(   -35.37), SIMDE_FLOAT32_C(   -40.40), SIMDE_FLOAT32_C(   -29.91),
        SIMDE_FLOAT32_C(    21.16), SIMDE_FLOAT32_C(   -40.49), SIMDE_FLOAT32_C(    14.61), SIMDE_FLOAT32_C(    47.05) },
      UINT8_C(101),
      { SIMDE_FLOAT32_C(    36.93), SIMDE_FLOAT32_C(    13.07), SIMDE_FLOAT32_C(   -44.42), SIMDE_FLOAT32_C(    44.87),
        SIMDE_FLOAT32_C(   -20.91), SIMDE_FLOAT32_C(   -49.83), SIMDE_FLOAT32_C(     7.11), SIMDE_FLOAT32_C(     2.98) },
      { SIMDE_FLOAT32_C(    18.08), SIMDE_FLOAT32_C(   -24.95), SIMDE_FLOAT32_C(    -9.92), SIMDE_FLOAT32_C(    12.44),
        SIMDE_FLOAT32_C(    28.10), SIMDE_FLOAT32_C(   -33.34), SIMDE_FLOAT32_C(    -6.24), SIMDE_FLOAT32_C(    30.46) },
      { SIMDE_FLOAT32_C(   706.39), SIMDE_FLOAT32_C(   -35.37), SIMDE_FLOAT32_C(   396.57), SIMDE_FLOAT32_C(   -29.91),
        SIMDE_FLOAT32_C(    21.16), SIMDE_FLOAT32_C(24108398694754935001990561792.00), SIMDE_FLOAT32_C(   -29.50), SIMDE_FLOAT32_C(    47.05) } },
    { { SIMDE_FLOAT32_C(    -6.28), SIMDE_FLOAT32_C(     5.72), SIMDE_FLOAT32_C(   -34.13), SIMDE_FLOAT32_C(    28.30),
        SIMDE_FLOAT32_C(   -44.56), SIMDE_FLOAT32_C(    14.29), SIMDE_FLOAT32_C(    39.35), SIMDE_FLOAT32_C(    11.62) },
      UINT8_C(117),
      { SIMDE_FLOAT32_C(    34.48), SIMDE_FLOAT32_C(    -9.50), SIMDE_FLOAT32_C(     4.65), SIMDE_FLOAT32_C(    -6.05),
        SIMDE_FLOAT32_C(    10.98), SIMDE_FLOAT32_C(    21.90), SIMDE_FLOAT32_C(    -1.13), SIMDE_FLOAT32_C(    18.04) },
      { SIMDE_FLOAT32_C(     5.92), SIMDE_FLOAT32_C(    20.32), SIMDE_FLOAT32_C(   -24.85), SIMDE_FLOAT32_C(   -12.17),
        SIMDE_FLOAT32_C(    26.48), SIMDE_FLOAT32_C(    -6.62), SIMDE_FLOAT32_C(   -34.72), SIMDE_FLOAT32_C(    13.42) },
      {     -SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(     5.72), SIMDE_FLOAT32_C(11551744039321600.00), SIMDE_FLOAT32_C(    28.30),
        SIMDE_FLOAT32_C(  5349.92), SIMDE_FLOAT32_C(-6323841.50), SIMDE_FLOAT32_C(  5453.16), SIMDE_FLOAT32_C(    11.62) } },
    { { SIMDE_FLOAT32_C(    16.02), SIMDE_FLOAT32_C(    14.71), SIMDE_FLOAT32_C(    31.29), SIMDE_FLOAT32_C(     9.84),
        SIMDE_FLOAT32_C(   -16.73), SIMDE_FLOAT32_C(   -26.29), SIMDE_FLOAT32_C(    16.15), SIMDE_FLOAT32_C(    16.31) },
      UINT8_C(236),
      { SIMDE_FLOAT32_C(   -43.56), SIMDE_FLOAT32_C(   -29.14), SIMDE_FLOAT32_C(     8.29), SIMDE_FLOAT32_C(   -14.47),
        SIMDE_FLOAT32_C(   -28.97), SIMDE_FLOAT32_C(   -34.60), SIMDE_FLOAT32_C(    38.51), SIMDE_FLOAT32_C(    39.12) },
      { SIMDE_FLOAT32_C(    -9.55), SIMDE_FLOAT32_C(   -21.41), SIMDE_FLOAT32_C(     1.56), SIMDE_FLOAT32_C(   -31.45),
        SIMDE_FLOAT32_C(    -4.75), SIMDE_FLOAT32_C(    45.32), SIMDE_FLOAT32_C(    49.01), SIMDE_FLOAT32_C(   -20.27) },
      { SIMDE_FLOAT32_C(    16.02), SIMDE_FLOAT32_C(    14.71), SIMDE_FLOAT32_C(    44.12), SIMDE_FLOAT32_C(   462.82),
        SIMDE_FLOAT32_C(   -16.73), SIMDE_FLOAT32_C(24190605650488729785870581760.00), SIMDE_FLOAT32_C(  1902.65), SIMDE_FLOAT32_C(15953551319997245030400.00) } },
    { { SIMDE_FLOAT32_C(   -29.26), SIMDE_FLOAT32_C(   -32.51), SIMDE_FLOAT32_C(    34.54), SIMDE_FLOAT32_C(   -29.58),
        SIMDE_FLOAT32_C(   -37.63), SIMDE_FLOAT32_C(    49.17), SIMDE_FLOAT32_C(   -19.98), SIMDE_FLOAT32_C(   -17.54) },
      UINT8_C(127),
      { SIMDE_FLOAT32_C(   -14.19), SIMDE_FLOAT32_C(     3.66), SIMDE_FLOAT32_C(    23.68), SIMDE_FLOAT32_C(    46.80),
        SIMDE_FLOAT32_C(   -24.43), SIMDE_FLOAT32_C(   -27.45), SIMDE_FLOAT32_C(    14.84), SIMDE_FLOAT32_C(    31.49) },
      { SIMDE_FLOAT32_C(    42.87), SIMDE_FLOAT32_C(    39.99), SIMDE_FLOAT32_C(   -30.68), SIMDE_FLOAT32_C(    19.36),
        SIMDE_FLOAT32_C(   -16.64), SIMDE_FLOAT32_C(   -15.40), SIMDE_FLOAT32_C(   -17.23), SIMDE_FLOAT32_C(   -10.19) },
      { SIMDE_FLOAT32_C(  4679.85), SIMDE_FLOAT32_C(-29088496073108223009442171453440.00),      SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(-9609989324800.00),
        SIMDE_FLOAT32_C(7910457856.00), SIMDE_FLOAT32_C(   465.74),     -SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(   -17.54) } },
    { { SIMDE_FLOAT32_C(    12.48), SIMDE_FLOAT32_C(   -41.56), SIMDE_FLOAT32_C(    40.16), SIMDE_FLOAT32_C(   -10.95),
        SIMDE_FLOAT32_C(    24.46), SIMDE_FLOAT32_C(     4.87), SIMDE_FLOAT32_C(   -29.66), SIMDE_FLOAT32_C(   -15.69) },
      UINT8_C(174),
      { SIMDE_FLOAT32_C(   -31.86), SIMDE_FLOAT32_C(    -8.89), SIMDE_FLOAT32_C(    -4.91), SIMDE_FLOAT32_C(    -6.29),
        SIMDE_FLOAT32_C(    13.66), SIMDE_FLOAT32_C(   -40.08), SIMDE_FLOAT32_C(   -24.80), SIMDE_FLOAT32_C(     6.53) },
      { SIMDE_FLOAT32_C(    49.91), SIMDE_FLOAT32_C(    -5.48), SIMDE_FLOAT32_C(   -24.11), SIMDE_FLOAT32_C(   -16.73),
        SIMDE_FLOAT32_C(    29.12), SIMDE_FLOAT32_C(     8.66), SIMDE_FLOAT32_C(    23.08), SIMDE_FLOAT32_C(   -15.43) },
      { SIMDE_FLOAT32_C(    12.48), SIMDE_FLOAT32_C(11195502271922176.00), SIMDE_FLOAT32_C(   153.42), SIMDE_FLOAT32_C(-13517554281552543744.00),
        SIMDE_FLOAT32_C(    24.46), SIMDE_FLOAT32_C(  -340.13), SIMDE_FLOAT32_C(   -29.66),      SIMDE_MATH_INFINITYF } },
    { { SIMDE_FLOAT32_C(   -40.43), SIMDE_FLOAT32_C(    13.45), SIMDE_FLOAT32_C(   -42.45), SIMDE_FLOAT32_C(    -7.68),
        SIMDE_FLOAT32_C(    33.78), SIMDE_FLOAT32_C(     9.61), SIMDE_FLOAT32_C(   -47.80), SIMDE_FLOAT32_C(   -14.17) },
      UINT8_C(221),
      { SIMDE_FLOAT32_C(   -45.55), SIMDE_FLOAT32_C(    47.06), SIMDE_FLOAT32_C(    12.77), SIMDE_FLOAT32_C(   -28.83),
        SIMDE_FLOAT32_C(    37.41), SIMDE_FLOAT32_C(    -3.34), SIMDE_FLOAT32_C(   -32.47), SIMDE_FLOAT32_C(    49.71) },
      { SIMDE_FLOAT32_C(   -45.42), SIMDE_FLOAT32_C(    34.06), SIMDE_FLOAT32_C(   -16.73), SIMDE_FLOAT32_C(     2.63),
        SIMDE_FLOAT32_C(    -3.83), SIMDE_FLOAT32_C(   -12.76), SIMDE_FLOAT32_C(    -9.10), SIMDE_FLOAT32_C(   -30.91) },
      { SIMDE_FLOAT32_C(  2018.44), SIMDE_FLOAT32_C(    13.45), SIMDE_FLOAT32_C(-19224753951762325664956416.00), SIMDE_FLOAT32_C(   -83.15),
        SIMDE_FLOAT32_C(  -108.82), SIMDE_FLOAT32_C(     9.61), SIMDE_FLOAT32_C(   244.47), SIMDE_FLOAT32_C(-13517554281552543744.00) } },
    { { SIMDE_FLOAT32_C(    23.26), SIMDE_FLOAT32_C(     2.87), SIMDE_FLOAT32_C(   -48.26), SIMDE_FLOAT32_C(   -48.30),
        SIMDE_FLOAT32_C(    22.16), SIMDE_FLOAT32_C(    35.34), SIMDE_FLOAT32_C(   -43.42), SIMDE_FLOAT32_C(    32.62) },
      UINT8_C(169),
      { SIMDE_FLOAT32_C(    38.93), SIMDE_FLOAT32_C(    24.44), SIMDE_FLOAT32_C(    42.37), SIMDE_FLOAT32_C(     0.39),
        SIMDE_FLOAT32_C(   -32.05), SIMDE_FLOAT32_C(   -40.71), SIMDE_FLOAT32_C(   -42.65), SIMDE_FLOAT32_C(   -23.47) },
      { SIMDE_FLOAT32_C(    11.99), SIMDE_FLOAT32_C(   -48.15), SIMDE_FLOAT32_C(   -28.11), SIMDE_FLOAT32_C(    46.40),
        SIMDE_FLOAT32_C(    33.97), SIMDE_FLOAT32_C(    -2.45), SIMDE_FLOAT32_C(    -2.21), SIMDE_FLOAT32_C(    38.42) },
      { SIMDE_FLOAT32_C(7596933632.00), SIMDE_FLOAT32_C(     2.87), SIMDE_FLOAT32_C(   -48.26), SIMDE_FLOAT32_C(   -30.32),
        SIMDE_FLOAT32_C(    22.16), SIMDE_FLOAT32_C(16308074682663850475520.00), SIMDE_FLOAT32_C(   -43.42), SIMDE_FLOAT32_C(  -861.47) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m256 tmp, src, r;
    simde__m256bh a, b;

    src = simde_mm256_loadu_ps(test_vec[i].src);

    tmp = simde_mm256_loadu_ps(test_vec[i].a);
    simde_memcpy(&a, &tmp, sizeof(tmp));

    tmp = simde_mm256_loadu_ps(test_vec[i].b);
    simde_memcpy(&b, &tmp, sizeof(tmp));

    r = simde_mm256_mask_dpbf16_ps(src, test_vec[i].k, a, b);
    simde_test_x86_assert_equal_f32x8(r, simde_mm256_loadu_ps(test_vec[i].r), 1);
  }

  return 0;
#else
  fputc('\n', stdout);
  simde_float32 values[8 * 2 * sizeof(simde__m256)];
  simde_test_x86_random_f32x8_full(8, 2, values, -50.0f, 50.0f, SIMDE_TEST_VEC_FLOAT_NAN);

  for (size_t i = 0 ; i < 8 ; i++) {
    simde__m256 src = simde_test_x86_random_f32x8(SIMDE_FLOAT32_C(-50.0), SIMDE_FLOAT32_C(50.0));
    simde__mmask8 k = simde_test_x86_random_mmask8();
    simde__m256bh a = HEDLEY_REINTERPRET_CAST(simde__m256bh, simde_test_x86_random_extract_f32x8(i, 2, 0, values));
    simde__m256bh b = HEDLEY_REINTERPRET_CAST(simde__m256bh, simde_test_x86_random_extract_f32x8(i, 2, 1, values));
    simde__m256 r = simde_mm256_mask_dpbf16_ps(src, k, a, b);

    simde_test_x86_write_f32x8(2, src, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_mmask8(2, k, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_f32x8(2, HEDLEY_REINTERPRET_CAST(simde__m256, a), SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_f32x8(2, HEDLEY_REINTERPRET_CAST(simde__m256, b), SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_f32x8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm256_maskz_dpbf16_ps (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const simde__mmask8 k;
    const simde_float32 src[8];
    const simde_float32 a[8];
    const simde_float32 b[8];
    const simde_float32 r[8];
  } test_vec[] = {
    #if !defined(SIMDE_FAST_MATH)
    { UINT8_C(205),
      { SIMDE_FLOAT32_C(   -36.42), SIMDE_FLOAT32_C(   -49.03), SIMDE_FLOAT32_C(   -38.95), SIMDE_FLOAT32_C(    12.54),
        SIMDE_FLOAT32_C(   -41.04), SIMDE_FLOAT32_C(    38.86), SIMDE_FLOAT32_C(    -1.22), SIMDE_FLOAT32_C(   -10.59) },
      {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(   -49.55),            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(    27.62),
        SIMDE_FLOAT32_C(   -28.81), SIMDE_FLOAT32_C(    21.94), SIMDE_FLOAT32_C(    12.16), SIMDE_FLOAT32_C(    -8.39) },
      { SIMDE_FLOAT32_C(    34.31),            SIMDE_MATH_NANF,            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(   -33.23),
        SIMDE_FLOAT32_C(   -18.34), SIMDE_FLOAT32_C(   -38.83), SIMDE_FLOAT32_C(   -36.16), SIMDE_FLOAT32_C(    49.05) },
      {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(     0.00),            SIMDE_MATH_NANF,      SIMDE_MATH_INFINITYF,
        SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(  -437.72), SIMDE_FLOAT32_C(  -420.96) } },
    #endif
    { UINT8_C(205),
      { SIMDE_FLOAT32_C(    47.49), SIMDE_FLOAT32_C(    31.73), SIMDE_FLOAT32_C(    37.79), SIMDE_FLOAT32_C(    38.51),
        SIMDE_FLOAT32_C(    -2.46), SIMDE_FLOAT32_C(    11.57), SIMDE_FLOAT32_C(    25.38), SIMDE_FLOAT32_C(    49.11) },
      { SIMDE_FLOAT32_C(    43.49), SIMDE_FLOAT32_C(     4.63), SIMDE_FLOAT32_C(   -27.84), SIMDE_FLOAT32_C(    41.68),
        SIMDE_FLOAT32_C(    23.72), SIMDE_FLOAT32_C(     0.70), SIMDE_FLOAT32_C(     4.16), SIMDE_FLOAT32_C(    32.17) },
      { SIMDE_FLOAT32_C(    -9.14), SIMDE_FLOAT32_C(    43.22), SIMDE_FLOAT32_C(     6.63), SIMDE_FLOAT32_C(    45.73),
        SIMDE_FLOAT32_C(   -36.44), SIMDE_FLOAT32_C(    40.93), SIMDE_FLOAT32_C(    33.88), SIMDE_FLOAT32_C(     7.61) },
      { SIMDE_FLOAT32_C(-29088496073108223009442171453440.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(  -146.05), SIMDE_FLOAT32_C(16100548811834618019840.00),
        SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(   165.65), SIMDE_FLOAT32_C(   292.11) } },
    { UINT8_C(227),
      { SIMDE_FLOAT32_C(    43.82), SIMDE_FLOAT32_C(   -10.38), SIMDE_FLOAT32_C(    28.47), SIMDE_FLOAT32_C(   -13.83),
        SIMDE_FLOAT32_C(    17.93), SIMDE_FLOAT32_C(    24.26), SIMDE_FLOAT32_C(    35.71), SIMDE_FLOAT32_C(    16.82) },
      { SIMDE_FLOAT32_C(    41.39), SIMDE_FLOAT32_C(   -11.67), SIMDE_FLOAT32_C(   -14.77), SIMDE_FLOAT32_C(   -37.42),
        SIMDE_FLOAT32_C(   -39.73), SIMDE_FLOAT32_C(    47.39), SIMDE_FLOAT32_C(     4.19), SIMDE_FLOAT32_C(    44.58) },
      { SIMDE_FLOAT32_C(     8.72), SIMDE_FLOAT32_C(   -24.17), SIMDE_FLOAT32_C(   -38.65), SIMDE_FLOAT32_C(    40.38),
        SIMDE_FLOAT32_C(   -13.00), SIMDE_FLOAT32_C(   -24.81), SIMDE_FLOAT32_C(    39.44), SIMDE_FLOAT32_C(   -19.51) },
      { SIMDE_FLOAT32_C(   402.18), SIMDE_FLOAT32_C(-9526774333440.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00),
        SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(-6337145.00), SIMDE_FLOAT32_C(   200.07), SIMDE_FLOAT32_C(  -850.93) } },
    { UINT8_C( 43),
      { SIMDE_FLOAT32_C(   -32.90), SIMDE_FLOAT32_C(     7.38), SIMDE_FLOAT32_C(   -28.27), SIMDE_FLOAT32_C(   -32.39),
        SIMDE_FLOAT32_C(    20.96), SIMDE_FLOAT32_C(   -27.31), SIMDE_FLOAT32_C(   -21.35), SIMDE_FLOAT32_C(   -16.50) },
      { SIMDE_FLOAT32_C(    29.83), SIMDE_FLOAT32_C(   -38.41), SIMDE_FLOAT32_C(   -27.83), SIMDE_FLOAT32_C(     3.55),
        SIMDE_FLOAT32_C(    12.29), SIMDE_FLOAT32_C(    26.34), SIMDE_FLOAT32_C(   -14.28), SIMDE_FLOAT32_C(   -46.85) },
      { SIMDE_FLOAT32_C(    19.55), SIMDE_FLOAT32_C(    42.34), SIMDE_FLOAT32_C(    48.89), SIMDE_FLOAT32_C(    33.11),
        SIMDE_FLOAT32_C(    33.28), SIMDE_FLOAT32_C(    32.76), SIMDE_FLOAT32_C(    -9.28), SIMDE_FLOAT32_C(    24.67) },
      { SIMDE_FLOAT32_C(-6329053.00), SIMDE_FLOAT32_C( -1613.12), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(16922581844619299913728.00),
        SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(   832.38), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00) } },
    { UINT8_C(241),
      { SIMDE_FLOAT32_C(   -32.49), SIMDE_FLOAT32_C(    32.27), SIMDE_FLOAT32_C(    21.07), SIMDE_FLOAT32_C(    38.46),
        SIMDE_FLOAT32_C(    29.77), SIMDE_FLOAT32_C(     2.80), SIMDE_FLOAT32_C(    26.25), SIMDE_FLOAT32_C(    18.28) },
      { SIMDE_FLOAT32_C(   -28.91), SIMDE_FLOAT32_C(    25.95), SIMDE_FLOAT32_C(    37.25), SIMDE_FLOAT32_C(   -18.64),
        SIMDE_FLOAT32_C(    23.34), SIMDE_FLOAT32_C(    -8.56), SIMDE_FLOAT32_C(   -24.07), SIMDE_FLOAT32_C(   -17.94) },
      { SIMDE_FLOAT32_C(    17.27), SIMDE_FLOAT32_C(   -12.72), SIMDE_FLOAT32_C(   -27.55), SIMDE_FLOAT32_C(   -45.73),
        SIMDE_FLOAT32_C(    12.48), SIMDE_FLOAT32_C(   -38.12), SIMDE_FLOAT32_C(   -15.24), SIMDE_FLOAT32_C(    -7.70) },
      { SIMDE_FLOAT32_C(  -530.58), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00),
        SIMDE_FLOAT32_C(   318.94),     -SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(   390.75), SIMDE_FLOAT32_C(   155.69) } },
    { UINT8_C( 27),
      { SIMDE_FLOAT32_C(   -12.18), SIMDE_FLOAT32_C(    -6.34), SIMDE_FLOAT32_C(    49.45), SIMDE_FLOAT32_C(   -43.57),
        SIMDE_FLOAT32_C(   -12.52), SIMDE_FLOAT32_C(   -10.93), SIMDE_FLOAT32_C(    34.90), SIMDE_FLOAT32_C(    23.65) },
      { SIMDE_FLOAT32_C(   -26.52), SIMDE_FLOAT32_C(     6.93), SIMDE_FLOAT32_C(    45.85), SIMDE_FLOAT32_C(    35.77),
        SIMDE_FLOAT32_C(   -16.73), SIMDE_FLOAT32_C(   -18.43), SIMDE_FLOAT32_C(    38.93), SIMDE_FLOAT32_C(   -47.18) },
      { SIMDE_FLOAT32_C(   -26.09), SIMDE_FLOAT32_C(    37.81), SIMDE_FLOAT32_C(    35.93), SIMDE_FLOAT32_C(   -42.81),
        SIMDE_FLOAT32_C(    20.58), SIMDE_FLOAT32_C(   -23.35), SIMDE_FLOAT32_C(    31.86), SIMDE_FLOAT32_C(    41.67) },
      { SIMDE_FLOAT32_C(   676.82), SIMDE_FLOAT32_C(   250.16), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C( -1571.88),
        SIMDE_FLOAT32_C(  -353.33), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00) } },
    { UINT8_C(141),
      { SIMDE_FLOAT32_C(     9.16), SIMDE_FLOAT32_C(     9.35), SIMDE_FLOAT32_C(    23.82), SIMDE_FLOAT32_C(     5.86),
        SIMDE_FLOAT32_C(    26.46), SIMDE_FLOAT32_C(   -18.80), SIMDE_FLOAT32_C(    27.59), SIMDE_FLOAT32_C(    44.06) },
      { SIMDE_FLOAT32_C(   -47.40), SIMDE_FLOAT32_C(    19.10), SIMDE_FLOAT32_C(   -26.98), SIMDE_FLOAT32_C(    25.94),
        SIMDE_FLOAT32_C(   -39.45), SIMDE_FLOAT32_C(    -1.04), SIMDE_FLOAT32_C(   -42.00), SIMDE_FLOAT32_C(    27.82) },
      { SIMDE_FLOAT32_C(    36.24), SIMDE_FLOAT32_C(   -19.56), SIMDE_FLOAT32_C(    32.09), SIMDE_FLOAT32_C(    -1.28),
        SIMDE_FLOAT32_C(    -7.67), SIMDE_FLOAT32_C(   -33.16), SIMDE_FLOAT32_C(    41.02), SIMDE_FLOAT32_C(    15.80) },
      { SIMDE_FLOAT32_C(7872182784.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(-28871237596213638771197375152128.00), SIMDE_FLOAT32_C(   -27.09),
        SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(   481.12) } },
    { UINT8_C(160),
      { SIMDE_FLOAT32_C(   -49.72), SIMDE_FLOAT32_C(   -27.29), SIMDE_FLOAT32_C(   -14.35), SIMDE_FLOAT32_C(   -18.06),
        SIMDE_FLOAT32_C(    -9.77), SIMDE_FLOAT32_C(   -32.07), SIMDE_FLOAT32_C(   -47.00), SIMDE_FLOAT32_C(   -21.31) },
      { SIMDE_FLOAT32_C(    23.78), SIMDE_FLOAT32_C(    36.87), SIMDE_FLOAT32_C(     1.58), SIMDE_FLOAT32_C(   -42.96),
        SIMDE_FLOAT32_C(   -31.56), SIMDE_FLOAT32_C(    -9.50), SIMDE_FLOAT32_C(   -40.14), SIMDE_FLOAT32_C(    -7.65) },
      { SIMDE_FLOAT32_C(   -21.68), SIMDE_FLOAT32_C(    45.79), SIMDE_FLOAT32_C(    -0.46), SIMDE_FLOAT32_C(    48.89),
        SIMDE_FLOAT32_C(   -27.56), SIMDE_FLOAT32_C(   -18.60), SIMDE_FLOAT32_C(    40.56), SIMDE_FLOAT32_C(   -24.97) },
      { SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00),
        SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(   143.68), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(7684751360.00) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m256 tmp, src, r;
    simde__m256bh a, b;

    src = simde_mm256_loadu_ps(test_vec[i].src);

    tmp = simde_mm256_loadu_ps(test_vec[i].a);
    simde_memcpy(&a, &tmp, sizeof(tmp));

    tmp = simde_mm256_loadu_ps(test_vec[i].b);
    simde_memcpy(&b, &tmp, sizeof(tmp));

    r = simde_mm256_maskz_dpbf16_ps(test_vec[i].k, src, a, b);
    simde_test_x86_assert_equal_f32x8(r, simde_mm256_loadu_ps(test_vec[i].r), 1);
  }

  return 0;
#else
  fputc('\n', stdout);
  simde_float32 values[8 * 2 * sizeof(simde__m256)];
  simde_test_x86_random_f32x8_full(8, 2, values, -50.0f, 50.0f, SIMDE_TEST_VEC_FLOAT_NAN);

  for (size_t i = 0 ; i < 8 ; i++) {
    simde__mmask8 k = simde_test_x86_random_mmask8();
    simde__m256 src = simde_test_x86_random_f32x8(SIMDE_FLOAT32_C(-50.0), SIMDE_FLOAT32_C(50.0));
    simde__m256bh a = HEDLEY_REINTERPRET_CAST(simde__m256bh, simde_test_x86_random_extract_f32x8(i, 2, 0, values));
    simde__m256bh b = HEDLEY_REINTERPRET_CAST(simde__m256bh, simde_test_x86_random_extract_f32x8(i, 2, 1, values));
    simde__m256 r = simde_mm256_maskz_dpbf16_ps(k, src, a, b);

    simde_test_x86_write_mmask8(2, k, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_f32x8(2, src, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_f32x8(2, HEDLEY_REINTERPRET_CAST(simde__m256, a), SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_f32x8(2, HEDLEY_REINTERPRET_CAST(simde__m256, b), SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_f32x8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm512_dpbf16_ps (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const simde_float32 src[16];
    const simde_float32 a[16];
    const simde_float32 b[16];
    const simde_float32 r[16];
  } test_vec[] = {
    { { SIMDE_FLOAT32_C(    -4.44), SIMDE_FLOAT32_C(    40.05), SIMDE_FLOAT32_C(    12.00), SIMDE_FLOAT32_C(    39.47),
        SIMDE_FLOAT32_C(    11.52), SIMDE_FLOAT32_C(   -31.72), SIMDE_FLOAT32_C(    49.75), SIMDE_FLOAT32_C(   -30.71),
        SIMDE_FLOAT32_C(     3.12), SIMDE_FLOAT32_C(   -12.10), SIMDE_FLOAT32_C(    39.10), SIMDE_FLOAT32_C(     8.78),
        SIMDE_FLOAT32_C(   -20.18), SIMDE_FLOAT32_C(   -32.50), SIMDE_FLOAT32_C(     2.81), SIMDE_FLOAT32_C(    -9.14) },
      {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(   -43.59),            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(   -16.76),
        SIMDE_FLOAT32_C(   -26.37), SIMDE_FLOAT32_C(    48.72), SIMDE_FLOAT32_C(   -46.46), SIMDE_FLOAT32_C(    22.60),
        SIMDE_FLOAT32_C(   -14.26), SIMDE_FLOAT32_C(   -33.63), SIMDE_FLOAT32_C(     8.09), SIMDE_FLOAT32_C(    25.18),
        SIMDE_FLOAT32_C(   -22.07), SIMDE_FLOAT32_C(    42.28), SIMDE_FLOAT32_C(    -2.69), SIMDE_FLOAT32_C(    16.71) },
      { SIMDE_FLOAT32_C(    48.18),            SIMDE_MATH_NANF,            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(    44.57),
        SIMDE_FLOAT32_C(    31.61), SIMDE_FLOAT32_C(   -25.05), SIMDE_FLOAT32_C(    49.98), SIMDE_FLOAT32_C(    18.38),
        SIMDE_FLOAT32_C(     7.25), SIMDE_FLOAT32_C(    30.69), SIMDE_FLOAT32_C(   -33.02), SIMDE_FLOAT32_C(    22.01),
        SIMDE_FLOAT32_C(    37.39), SIMDE_FLOAT32_C(   -47.43), SIMDE_FLOAT32_C(   -36.63), SIMDE_FLOAT32_C(   -22.09) },
      {            SIMDE_MATH_NANF,            SIMDE_MATH_NANF,            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(  -705.91),
             SIMDE_MATH_INFINITYF,     -SIMDE_MATH_INFINITYF,      SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(   382.73),
        SIMDE_FLOAT32_C(  -100.19), SIMDE_FLOAT32_C( -1038.04), SIMDE_FLOAT32_C(  4918.54), SIMDE_FLOAT32_C(  5707.03),
        SIMDE_FLOAT32_C(  -839.68), SIMDE_FLOAT32_C( -2028.81), SIMDE_FLOAT32_C(   100.90), SIMDE_FLOAT32_C(  -374.89) } },
    { { SIMDE_FLOAT32_C(     5.69), SIMDE_FLOAT32_C(    47.63), SIMDE_FLOAT32_C(   -46.05), SIMDE_FLOAT32_C(    37.97),
        SIMDE_FLOAT32_C(    25.96), SIMDE_FLOAT32_C(    45.47), SIMDE_FLOAT32_C(     9.16), SIMDE_FLOAT32_C(    16.69),
        SIMDE_FLOAT32_C(    12.15), SIMDE_FLOAT32_C(    45.50), SIMDE_FLOAT32_C(   -23.77), SIMDE_FLOAT32_C(   -14.89),
        SIMDE_FLOAT32_C(     2.59), SIMDE_FLOAT32_C(    -4.17), SIMDE_FLOAT32_C(    22.38), SIMDE_FLOAT32_C(    48.14) },
      { SIMDE_FLOAT32_C(   -41.02), SIMDE_FLOAT32_C(    -9.86), SIMDE_FLOAT32_C(    11.15), SIMDE_FLOAT32_C(   -17.39),
        SIMDE_FLOAT32_C(   -11.14), SIMDE_FLOAT32_C(    14.70), SIMDE_FLOAT32_C(   -44.78), SIMDE_FLOAT32_C(    24.60),
        SIMDE_FLOAT32_C(    31.06), SIMDE_FLOAT32_C(    13.31), SIMDE_FLOAT32_C(    -0.22), SIMDE_FLOAT32_C(   -41.01),
        SIMDE_FLOAT32_C(     5.59), SIMDE_FLOAT32_C(    47.09), SIMDE_FLOAT32_C(    25.70), SIMDE_FLOAT32_C(     3.76) },
      { SIMDE_FLOAT32_C(   -25.07), SIMDE_FLOAT32_C(    36.83), SIMDE_FLOAT32_C(    -1.67), SIMDE_FLOAT32_C(   -43.46),
        SIMDE_FLOAT32_C(   -38.22), SIMDE_FLOAT32_C(    -1.70), SIMDE_FLOAT32_C(    24.92), SIMDE_FLOAT32_C(    19.03),
        SIMDE_FLOAT32_C(   -21.01), SIMDE_FLOAT32_C(    41.90), SIMDE_FLOAT32_C(    -8.96), SIMDE_FLOAT32_C(   -33.62),
        SIMDE_FLOAT32_C(    44.47), SIMDE_FLOAT32_C(     4.41), SIMDE_FLOAT32_C(    -5.71), SIMDE_FLOAT32_C(   -46.55) },
      { SIMDE_FLOAT32_C(  1030.69), SIMDE_FLOAT32_C(-9059159769088.00), SIMDE_FLOAT32_C(-19414829202697828884807680.00), SIMDE_FLOAT32_C(   789.44),
        SIMDE_FLOAT32_C(-13567093877453619200.00), SIMDE_FLOAT32_C(    20.57), SIMDE_FLOAT32_C( -1103.99), SIMDE_FLOAT32_C(-6323358.00),
        SIMDE_FLOAT32_C(7402290688.00), SIMDE_FLOAT32_C(7872184832.00), SIMDE_FLOAT32_C(16951404882234471088128.00), SIMDE_FLOAT32_C(  6674.23),
             SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(   202.93), SIMDE_FLOAT32_C(  -123.36), SIMDE_FLOAT32_C(  -126.24) } },
    { { SIMDE_FLOAT32_C(   -14.11), SIMDE_FLOAT32_C(   -15.62), SIMDE_FLOAT32_C(    37.62), SIMDE_FLOAT32_C(    47.41),
        SIMDE_FLOAT32_C(     2.66), SIMDE_FLOAT32_C(    37.37), SIMDE_FLOAT32_C(   -33.31), SIMDE_FLOAT32_C(   -44.22),
        SIMDE_FLOAT32_C(   -24.74), SIMDE_FLOAT32_C(   -44.20), SIMDE_FLOAT32_C(    14.56), SIMDE_FLOAT32_C(     5.08),
        SIMDE_FLOAT32_C(   -26.71), SIMDE_FLOAT32_C(   -32.63), SIMDE_FLOAT32_C(    45.94), SIMDE_FLOAT32_C(    28.98) },
      { SIMDE_FLOAT32_C(    44.55), SIMDE_FLOAT32_C(   -44.56), SIMDE_FLOAT32_C(   -13.93), SIMDE_FLOAT32_C(   -16.59),
        SIMDE_FLOAT32_C(    20.14), SIMDE_FLOAT32_C(    -8.72), SIMDE_FLOAT32_C(   -41.99), SIMDE_FLOAT32_C(     1.20),
        SIMDE_FLOAT32_C(   -45.41), SIMDE_FLOAT32_C(     7.79), SIMDE_FLOAT32_C(    10.19), SIMDE_FLOAT32_C(    10.18),
        SIMDE_FLOAT32_C(     4.88), SIMDE_FLOAT32_C(   -14.11), SIMDE_FLOAT32_C(   -36.06), SIMDE_FLOAT32_C(    29.81) },
      { SIMDE_FLOAT32_C(   -27.28), SIMDE_FLOAT32_C(    12.27), SIMDE_FLOAT32_C(    36.34), SIMDE_FLOAT32_C(   -15.50),
        SIMDE_FLOAT32_C(   -39.42), SIMDE_FLOAT32_C(    11.26), SIMDE_FLOAT32_C(   -46.47), SIMDE_FLOAT32_C(   -10.43),
        SIMDE_FLOAT32_C(     3.16), SIMDE_FLOAT32_C(    -5.43), SIMDE_FLOAT32_C(     5.95), SIMDE_FLOAT32_C(    -2.37),
        SIMDE_FLOAT32_C(    48.98), SIMDE_FLOAT32_C(   -49.76), SIMDE_FLOAT32_C(     1.08), SIMDE_FLOAT32_C(    43.53) },
      { SIMDE_FLOAT32_C( -1226.73), SIMDE_FLOAT32_C(7454850560.00), SIMDE_FLOAT32_C(-43874908454619293461082693981909811200.00), SIMDE_FLOAT32_C(   303.16),
        SIMDE_FLOAT32_C(  -787.25), SIMDE_FLOAT32_C(   -60.36),      SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(   -56.62),
        SIMDE_FLOAT32_C(  -167.56), SIMDE_FLOAT32_C(-6369878.50), SIMDE_FLOAT32_C(    75.05), SIMDE_FLOAT32_C(7759462400.00),
        SIMDE_FLOAT32_C(-8782671249408.00), SIMDE_FLOAT32_C(   666.98), SIMDE_FLOAT32_C(     7.13), SIMDE_FLOAT32_C(11379945347481600.00) } },
    { { SIMDE_FLOAT32_C(   -35.00), SIMDE_FLOAT32_C(    49.89), SIMDE_FLOAT32_C(    16.95), SIMDE_FLOAT32_C(    40.96),
        SIMDE_FLOAT32_C(    45.35), SIMDE_FLOAT32_C(   -23.89), SIMDE_FLOAT32_C(     7.65), SIMDE_FLOAT32_C(     7.50),
        SIMDE_FLOAT32_C(   -28.39), SIMDE_FLOAT32_C(    33.87), SIMDE_FLOAT32_C(    42.61), SIMDE_FLOAT32_C(    24.20),
        SIMDE_FLOAT32_C(   -20.29), SIMDE_FLOAT32_C(    15.00), SIMDE_FLOAT32_C(    22.34), SIMDE_FLOAT32_C(    15.59) },
      { SIMDE_FLOAT32_C(   -44.31), SIMDE_FLOAT32_C(    37.15), SIMDE_FLOAT32_C(   -23.06), SIMDE_FLOAT32_C(    25.83),
        SIMDE_FLOAT32_C(   -21.57), SIMDE_FLOAT32_C(   -15.05), SIMDE_FLOAT32_C(   -22.97), SIMDE_FLOAT32_C(   -16.98),
        SIMDE_FLOAT32_C(    42.74), SIMDE_FLOAT32_C(    37.22), SIMDE_FLOAT32_C(    43.20), SIMDE_FLOAT32_C(    -2.38),
        SIMDE_FLOAT32_C(   -26.89), SIMDE_FLOAT32_C(   -42.85), SIMDE_FLOAT32_C(   -22.57), SIMDE_FLOAT32_C(    -4.17) },
      { SIMDE_FLOAT32_C(    19.42), SIMDE_FLOAT32_C(   -36.23), SIMDE_FLOAT32_C(    30.33), SIMDE_FLOAT32_C(    29.99),
        SIMDE_FLOAT32_C(    25.03), SIMDE_FLOAT32_C(    33.86), SIMDE_FLOAT32_C(   -30.44), SIMDE_FLOAT32_C(   -21.81),
        SIMDE_FLOAT32_C(   -21.57), SIMDE_FLOAT32_C(    25.52), SIMDE_FLOAT32_C(    25.82), SIMDE_FLOAT32_C(   -22.59),
        SIMDE_FLOAT32_C(    25.76), SIMDE_FLOAT32_C(   -23.09), SIMDE_FLOAT32_C(   -29.06), SIMDE_FLOAT32_C(    31.44) },
      { SIMDE_FLOAT32_C(11195502271922176.00), SIMDE_FLOAT32_C(  3838.39), SIMDE_FLOAT32_C(-13616351998377984000.00), SIMDE_FLOAT32_C(7496008704.00),
        SIMDE_FLOAT32_C(  -492.15), SIMDE_FLOAT32_C(-43641255095985226217798821647094906880.00), SIMDE_FLOAT32_C(   702.48),     -SIMDE_MATH_INFINITYF,
        SIMDE_FLOAT32_C(  4420.36), SIMDE_FLOAT32_C(-6296622.50), SIMDE_FLOAT32_C(  1149.86), SIMDE_FLOAT32_C(-6343602.50),
        SIMDE_FLOAT32_C(  -712.32), SIMDE_FLOAT32_C(-13595241375124684800.00), SIMDE_FLOAT32_C(-6335325.00), SIMDE_FLOAT32_C(  -114.81) } },
    { { SIMDE_FLOAT32_C(    49.37), SIMDE_FLOAT32_C(     9.96), SIMDE_FLOAT32_C(    13.00), SIMDE_FLOAT32_C(     2.04),
        SIMDE_FLOAT32_C(    -2.68), SIMDE_FLOAT32_C(    29.69), SIMDE_FLOAT32_C(     7.82), SIMDE_FLOAT32_C(    22.58),
        SIMDE_FLOAT32_C(    35.49), SIMDE_FLOAT32_C(   -27.63), SIMDE_FLOAT32_C(   -22.33), SIMDE_FLOAT32_C(   -41.22),
        SIMDE_FLOAT32_C(   -10.25), SIMDE_FLOAT32_C(   -26.39), SIMDE_FLOAT32_C(    37.76), SIMDE_FLOAT32_C(     4.74) },
      { SIMDE_FLOAT32_C(   -35.94), SIMDE_FLOAT32_C(    -2.12), SIMDE_FLOAT32_C(     7.27), SIMDE_FLOAT32_C(    -7.51),
        SIMDE_FLOAT32_C(    32.83), SIMDE_FLOAT32_C(    34.30), SIMDE_FLOAT32_C(    25.52), SIMDE_FLOAT32_C(    25.57),
        SIMDE_FLOAT32_C(    21.52), SIMDE_FLOAT32_C(    18.72), SIMDE_FLOAT32_C(   -26.81), SIMDE_FLOAT32_C(    44.63),
        SIMDE_FLOAT32_C(    25.87), SIMDE_FLOAT32_C(     0.61), SIMDE_FLOAT32_C(    -9.53), SIMDE_FLOAT32_C(    -4.72) },
      { SIMDE_FLOAT32_C(    14.39), SIMDE_FLOAT32_C(   -29.20), SIMDE_FLOAT32_C(   -24.72), SIMDE_FLOAT32_C(   -10.58),
        SIMDE_FLOAT32_C(   -45.34), SIMDE_FLOAT32_C(    -5.16), SIMDE_FLOAT32_C(    17.61), SIMDE_FLOAT32_C(   -16.90),
        SIMDE_FLOAT32_C(   -29.64), SIMDE_FLOAT32_C(    -6.56), SIMDE_FLOAT32_C(    10.51), SIMDE_FLOAT32_C(    46.11),
        SIMDE_FLOAT32_C(    20.34), SIMDE_FLOAT32_C(    31.45), SIMDE_FLOAT32_C(    27.56), SIMDE_FLOAT32_C(    34.40) },
      { SIMDE_FLOAT32_C(  -468.74), SIMDE_FLOAT32_C(    71.40), SIMDE_FLOAT32_C(  -165.53), SIMDE_FLOAT32_C(11287586370748416.00),
        SIMDE_FLOAT32_C(24108398694754935001990561792.00), SIMDE_FLOAT32_C(  -146.91), SIMDE_FLOAT32_C(-6297146.00), SIMDE_FLOAT32_C(  -407.73),
        SIMDE_FLOAT32_C(  -601.45), SIMDE_FLOAT32_C(22992560163250632273736761344.00), SIMDE_FLOAT32_C(15953551319997245030400.00), SIMDE_FLOAT32_C(  2005.78),
        SIMDE_FLOAT32_C(24752756156609532352108953600.00), SIMDE_FLOAT32_C(    -7.27),      SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(  -156.88) } },
    { { SIMDE_FLOAT32_C(   -26.51), SIMDE_FLOAT32_C(     4.71), SIMDE_FLOAT32_C(    -4.30), SIMDE_FLOAT32_C(   -31.16),
        SIMDE_FLOAT32_C(    30.82), SIMDE_FLOAT32_C(   -46.65), SIMDE_FLOAT32_C(    26.34), SIMDE_FLOAT32_C(   -47.57),
        SIMDE_FLOAT32_C(    37.22), SIMDE_FLOAT32_C(    18.96), SIMDE_FLOAT32_C(    26.63), SIMDE_FLOAT32_C(   -33.07),
        SIMDE_FLOAT32_C(   -16.05), SIMDE_FLOAT32_C(    -1.04), SIMDE_FLOAT32_C(    32.52), SIMDE_FLOAT32_C(   -16.67) },
      { SIMDE_FLOAT32_C(   -20.68), SIMDE_FLOAT32_C(   -15.17), SIMDE_FLOAT32_C(   -23.11), SIMDE_FLOAT32_C(   -37.85),
        SIMDE_FLOAT32_C(   -30.87), SIMDE_FLOAT32_C(   -47.59), SIMDE_FLOAT32_C(    37.72), SIMDE_FLOAT32_C(    40.65),
        SIMDE_FLOAT32_C(    21.13), SIMDE_FLOAT32_C(   -39.10), SIMDE_FLOAT32_C(    35.28), SIMDE_FLOAT32_C(    -3.01),
        SIMDE_FLOAT32_C(    11.52), SIMDE_FLOAT32_C(   -24.26), SIMDE_FLOAT32_C(    42.28), SIMDE_FLOAT32_C(   -24.09) },
      { SIMDE_FLOAT32_C(    -3.46), SIMDE_FLOAT32_C(   -32.45), SIMDE_FLOAT32_C(    15.33), SIMDE_FLOAT32_C(     1.21),
        SIMDE_FLOAT32_C(    12.39), SIMDE_FLOAT32_C(   -17.06), SIMDE_FLOAT32_C(    34.30), SIMDE_FLOAT32_C(    32.75),
        SIMDE_FLOAT32_C(    26.38), SIMDE_FLOAT32_C(    -5.19), SIMDE_FLOAT32_C(    28.87), SIMDE_FLOAT32_C(    -3.28),
        SIMDE_FLOAT32_C(   -23.74), SIMDE_FLOAT32_C(     6.42), SIMDE_FLOAT32_C(   -18.87), SIMDE_FLOAT32_C(     5.58) },
      {      SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(  5873.74), SIMDE_FLOAT32_C(-20542294200482956679577600.00),     -SIMDE_MATH_INFINITYF,
        SIMDE_FLOAT32_C(-29088496073108223009442171453440.00),      SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(-9609989324800.00), SIMDE_FLOAT32_C(  1278.81),
        SIMDE_FLOAT32_C(   594.39), SIMDE_FLOAT32_C(   221.28), SIMDE_FLOAT32_C(-9631464161280.00), SIMDE_FLOAT32_C(7496007680.00),
        SIMDE_FLOAT32_C(-40743953448922792401078804695390093312.00), SIMDE_FLOAT32_C(  4989.11), SIMDE_FLOAT32_C(-9631464161280.00), SIMDE_FLOAT32_C(  -150.17) } },
    { { SIMDE_FLOAT32_C(   -41.08), SIMDE_FLOAT32_C(    -4.48), SIMDE_FLOAT32_C(    35.36), SIMDE_FLOAT32_C(     6.24),
        SIMDE_FLOAT32_C(   -24.78), SIMDE_FLOAT32_C(    -6.82), SIMDE_FLOAT32_C(   -21.18), SIMDE_FLOAT32_C(   -39.29),
        SIMDE_FLOAT32_C(    15.56), SIMDE_FLOAT32_C(     6.49), SIMDE_FLOAT32_C(   -30.51), SIMDE_FLOAT32_C(   -44.70),
        SIMDE_FLOAT32_C(    30.10), SIMDE_FLOAT32_C(   -42.75), SIMDE_FLOAT32_C(    10.04), SIMDE_FLOAT32_C(   -46.41) },
      { SIMDE_FLOAT32_C(    41.25), SIMDE_FLOAT32_C(     8.02), SIMDE_FLOAT32_C(    17.73), SIMDE_FLOAT32_C(   -39.62),
        SIMDE_FLOAT32_C(    10.43), SIMDE_FLOAT32_C(     5.45), SIMDE_FLOAT32_C(   -48.98), SIMDE_FLOAT32_C(   -18.44),
        SIMDE_FLOAT32_C(    16.35), SIMDE_FLOAT32_C(    36.30), SIMDE_FLOAT32_C(    28.55), SIMDE_FLOAT32_C(   -22.13),
        SIMDE_FLOAT32_C(   -37.96), SIMDE_FLOAT32_C(    20.83), SIMDE_FLOAT32_C(     3.78), SIMDE_FLOAT32_C(     8.58) },
      { SIMDE_FLOAT32_C(    38.38), SIMDE_FLOAT32_C(   -30.89), SIMDE_FLOAT32_C(   -40.21), SIMDE_FLOAT32_C(     0.77),
        SIMDE_FLOAT32_C(     2.05), SIMDE_FLOAT32_C(    44.09), SIMDE_FLOAT32_C(   -16.48), SIMDE_FLOAT32_C(   -21.57),
        SIMDE_FLOAT32_C(   -11.10), SIMDE_FLOAT32_C(   -37.61), SIMDE_FLOAT32_C(    25.16), SIMDE_FLOAT32_C(    15.16),
        SIMDE_FLOAT32_C(    18.81), SIMDE_FLOAT32_C(   -43.72), SIMDE_FLOAT32_C(   -29.26), SIMDE_FLOAT32_C(    10.07) },
      { SIMDE_FLOAT32_C(  1536.73), SIMDE_FLOAT32_C(  -251.48), SIMDE_FLOAT32_C(23022783308740998003104415744.00), SIMDE_FLOAT32_C(11379945347481600.00),
        SIMDE_FLOAT32_C(-9609989324800.00),      SIMDE_MATH_INFINITYF,      SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(   355.77),
        SIMDE_FLOAT32_C(  -164.21), SIMDE_FLOAT32_C(16922581844619299913728.00), SIMDE_FLOAT32_C(24190605650488729785870581760.00), SIMDE_FLOAT32_C(  -379.34),
            -SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(  4429.62), SIMDE_FLOAT32_C(  -104.18), SIMDE_FLOAT32_C(    39.75) } },
    { { SIMDE_FLOAT32_C(    11.97), SIMDE_FLOAT32_C(   -44.25), SIMDE_FLOAT32_C(   -27.57), SIMDE_FLOAT32_C(    -7.21),
        SIMDE_FLOAT32_C(   -40.91), SIMDE_FLOAT32_C(    48.77), SIMDE_FLOAT32_C(    -4.79), SIMDE_FLOAT32_C(    46.32),
        SIMDE_FLOAT32_C(    17.73), SIMDE_FLOAT32_C(   -28.16), SIMDE_FLOAT32_C(   -36.75), SIMDE_FLOAT32_C(   -48.31),
        SIMDE_FLOAT32_C(    20.80), SIMDE_FLOAT32_C(    45.77), SIMDE_FLOAT32_C(   -14.99), SIMDE_FLOAT32_C(    29.72) },
      { SIMDE_FLOAT32_C(    14.30), SIMDE_FLOAT32_C(    38.47), SIMDE_FLOAT32_C(    20.44), SIMDE_FLOAT32_C(   -25.27),
        SIMDE_FLOAT32_C(    -6.08), SIMDE_FLOAT32_C(    21.47), SIMDE_FLOAT32_C(     6.29), SIMDE_FLOAT32_C(   -39.73),
        SIMDE_FLOAT32_C(     7.77), SIMDE_FLOAT32_C(   -15.17), SIMDE_FLOAT32_C(   -11.85), SIMDE_FLOAT32_C(    19.81),
        SIMDE_FLOAT32_C(   -44.34), SIMDE_FLOAT32_C(    41.93), SIMDE_FLOAT32_C(   -21.60), SIMDE_FLOAT32_C(    44.04) },
      { SIMDE_FLOAT32_C(   -38.96), SIMDE_FLOAT32_C(   -11.81), SIMDE_FLOAT32_C(    -5.19), SIMDE_FLOAT32_C(    13.09),
        SIMDE_FLOAT32_C(   -17.72), SIMDE_FLOAT32_C(    28.34), SIMDE_FLOAT32_C(    41.52), SIMDE_FLOAT32_C(    21.19),
        SIMDE_FLOAT32_C(    40.73), SIMDE_FLOAT32_C(    16.68), SIMDE_FLOAT32_C(   -13.65), SIMDE_FLOAT32_C(     9.54),
        SIMDE_FLOAT32_C(    22.97), SIMDE_FLOAT32_C(     7.08), SIMDE_FLOAT32_C(   -30.39), SIMDE_FLOAT32_C(   -12.73) },
      { SIMDE_FLOAT32_C(16308074682663850475520.00),      SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(  -133.27), SIMDE_FLOAT32_C(11089674277748736.00),
        SIMDE_FLOAT32_C(    65.94), SIMDE_FLOAT32_C(   652.62), SIMDE_FLOAT32_C(   255.88), SIMDE_FLOAT32_C(  -788.12),
        SIMDE_FLOAT32_C(7496008192.00), SIMDE_FLOAT32_C(-20329787708753822644961280.00), SIMDE_FLOAT32_C(   119.87), SIMDE_FLOAT32_C(-13616351998377984000.00),
        SIMDE_FLOAT32_C(-13604811524332847104.00), SIMDE_FLOAT32_C(   340.63), SIMDE_FLOAT32_C(   638.07), SIMDE_FLOAT32_C(  -528.53) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m512 tmp, src, r;
    simde__m512bh a, b;

    src = simde_mm512_loadu_ps(test_vec[i].src);

    tmp = simde_mm512_loadu_ps(test_vec[i].a);
    simde_memcpy(&a, &tmp, sizeof(tmp));

    tmp = simde_mm512_loadu_ps(test_vec[i].b);
    simde_memcpy(&b, &tmp, sizeof(tmp));

    r = simde_mm512_dpbf16_ps(src, a, b);
    simde_test_x86_assert_equal_f32x16(r, simde_mm512_loadu_ps(test_vec[i].r), 1);
  }

  return 0;
#else
  fputc('\n', stdout);
  simde_float32 values[8 * 2 * sizeof(simde__m512)];
  simde_test_x86_random_f32x16_full(8, 2, values, -50.0f, 50.0f, SIMDE_TEST_VEC_FLOAT_NAN);

  for (size_t i = 0 ; i < 8 ; i++) {
    simde__m512 src = simde_test_x86_random_f32x16(SIMDE_FLOAT32_C(-50.0), SIMDE_FLOAT32_C(50.0));
    simde__m512bh a = HEDLEY_REINTERPRET_CAST(simde__m512bh, simde_test_x86_random_extract_f32x16(i, 2, 0, values));
    simde__m512bh b = HEDLEY_REINTERPRET_CAST(simde__m512bh, simde_test_x86_random_extract_f32x16(i, 2, 1, values));
    simde__m512 r = simde_mm512_dpbf16_ps(src, a, b);

    simde_test_x86_write_f32x16(2, src, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_f32x16(2, HEDLEY_REINTERPRET_CAST(simde__m512, a), SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_f32x16(2, HEDLEY_REINTERPRET_CAST(simde__m512, b), SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_f32x16(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm512_mask_dpbf16_ps (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const simde_float32 src[16];
    const simde__mmask16 k;
    const uint16_t a[32];
    const uint16_t b[32];
    const simde_float32 r[16];
  } test_vec[] = {
    { { SIMDE_FLOAT32_C(   -47.03), SIMDE_FLOAT32_C(    44.54), SIMDE_FLOAT32_C(    -6.78), SIMDE_FLOAT32_C(   -46.91),
        SIMDE_FLOAT32_C(   -44.27), SIMDE_FLOAT32_C(    -4.56), SIMDE_FLOAT32_C(   -17.23), SIMDE_FLOAT32_C(    15.32),
        SIMDE_FLOAT32_C(   -18.60), SIMDE_FLOAT32_C(   -35.76), SIMDE_FLOAT32_C(    39.52), SIMDE_FLOAT32_C(   -27.00),
        SIMDE_FLOAT32_C(    12.52), SIMDE_FLOAT32_C(    41.56), SIMDE_FLOAT32_C(    36.86), SIMDE_FLOAT32_C(    13.89) },
      UINT16_C(25853),
      { UINT16_C(32256), UINT16_C(51123), UINT16_C(32256), UINT16_C(20931), UINT16_C(20926), UINT16_C(53592), UINT16_C(19283), UINT16_C(20945),
        UINT16_C(17541), UINT16_C(53557), UINT16_C(52152), UINT16_C(53302), UINT16_C(19069), UINT16_C(51517), UINT16_C(18826), UINT16_C(21030),
        UINT16_C(53643), UINT16_C(52451), UINT16_C(51772), UINT16_C(20760), UINT16_C(20819), UINT16_C(19976), UINT16_C(51320), UINT16_C(19604),
        UINT16_C(49715), UINT16_C(51702), UINT16_C(21037), UINT16_C(51626), UINT16_C(20799), UINT16_C(19603), UINT16_C(18478), UINT16_C(53450) },
      { UINT16_C(53485), UINT16_C(32256), UINT16_C(32256), UINT16_C(53614), UINT16_C(20547), UINT16_C(19869), UINT16_C(53725), UINT16_C(51631),
        UINT16_C(20402), UINT16_C(51759), UINT16_C(17646), UINT16_C(50749), UINT16_C(20170), UINT16_C(53312), UINT16_C(50957), UINT16_C(20506),
        UINT16_C(49940), UINT16_C(20383), UINT16_C(19940), UINT16_C(51575), UINT16_C(17562), UINT16_C(53356), UINT16_C(53588), UINT16_C(53776),
        UINT16_C(16742), UINT16_C(53606), UINT16_C(51434), UINT16_C(50511), UINT16_C(20038), UINT16_C(21009), UINT16_C(18020), UINT16_C(20598) },
      {     -SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(    44.54), SIMDE_FLOAT32_C(1315776170732191481856.00), SIMDE_FLOAT32_C(-1801541006017953792.00),
        SIMDE_FLOAT32_C(139314479790817280.00), SIMDE_FLOAT32_C(147692365807616.00), SIMDE_FLOAT32_C(16998724643323904.00), SIMDE_FLOAT32_C(1842080333985589755904.00),
        SIMDE_FLOAT32_C(   -18.60), SIMDE_FLOAT32_C(   -35.76), SIMDE_FLOAT32_C(-9034151033516851200.00), SIMDE_FLOAT32_C(   -27.00),
        SIMDE_FLOAT32_C(    12.52), SIMDE_FLOAT32_C(-89020850841321472.00), SIMDE_FLOAT32_C(54578560934149619712.00), SIMDE_FLOAT32_C(    13.89) } },
    { { SIMDE_FLOAT32_C(    18.20), SIMDE_FLOAT32_C(   -36.88), SIMDE_FLOAT32_C(    28.39), SIMDE_FLOAT32_C(   -36.01),
        SIMDE_FLOAT32_C(   -38.66), SIMDE_FLOAT32_C(    28.02), SIMDE_FLOAT32_C(    49.63), SIMDE_FLOAT32_C(   -45.64),
        SIMDE_FLOAT32_C(    49.68), SIMDE_FLOAT32_C(    35.12), SIMDE_FLOAT32_C(    26.47), SIMDE_FLOAT32_C(    36.36),
        SIMDE_FLOAT32_C(   -25.30), SIMDE_FLOAT32_C(    29.44), SIMDE_FLOAT32_C(    30.90), SIMDE_FLOAT32_C(    17.93) },
      UINT16_C(24671),
      { UINT16_C(20057), UINT16_C(19223), UINT16_C(20808), UINT16_C(18624), UINT16_C(51887), UINT16_C(20906), UINT16_C(20996), UINT16_C(53267),
        UINT16_C(52291), UINT16_C(16927), UINT16_C(18838), UINT16_C(53500), UINT16_C(19652), UINT16_C(53692), UINT16_C(20829), UINT16_C(53327),
        UINT16_C(20563), UINT16_C(19487), UINT16_C(17562), UINT16_C(51558), UINT16_C(20423), UINT16_C(18943), UINT16_C(51365), UINT16_C(52236),
        UINT16_C(19635), UINT16_C(20409), UINT16_C(20256), UINT16_C(50716), UINT16_C(20315), UINT16_C(52110), UINT16_C(52507), UINT16_C(17615) },
      { UINT16_C(21026), UINT16_C(53003), UINT16_C(53366), UINT16_C(52006), UINT16_C(53275), UINT16_C(53426), UINT16_C(16957), UINT16_C(11878),
        UINT16_C(19392), UINT16_C(53367), UINT16_C(18715), UINT16_C(52151), UINT16_C(53222), UINT16_C(16963), UINT16_C(11878), UINT16_C(53728),
        UINT16_C(53145), UINT16_C(53674), UINT16_C(51146), UINT16_C(53801), UINT16_C(19500), UINT16_C(20509), UINT16_C(52155), UINT16_C(52035),
        UINT16_C(19176), UINT16_C(53407), UINT16_C(20311), UINT16_C(50885), UINT16_C(49193), UINT16_C(53538), UINT16_C(20993), UINT16_C(49664) },
      { SIMDE_FLOAT32_C(158296460352492142592.00), SIMDE_FLOAT32_C(-886308406666513612800.00), SIMDE_FLOAT32_C(-2180403122892636684288.00), SIMDE_FLOAT32_C(6696927756288.00),
        SIMDE_FLOAT32_C(-1287087479324672.00), SIMDE_FLOAT32_C(    28.02), SIMDE_FLOAT32_C(-793060694684598272.00), SIMDE_FLOAT32_C(   -45.64),
        SIMDE_FLOAT32_C(    49.68), SIMDE_FLOAT32_C(    35.12), SIMDE_FLOAT32_C(    26.47), SIMDE_FLOAT32_C(    36.36),
        SIMDE_FLOAT32_C(   -25.30), SIMDE_FLOAT32_C(9682739198846566400.00), SIMDE_FLOAT32_C(809381295531491328.00), SIMDE_FLOAT32_C(    17.93) } },
    { { SIMDE_FLOAT32_C(   -36.63), SIMDE_FLOAT32_C(   -34.69), SIMDE_FLOAT32_C(     1.95), SIMDE_FLOAT32_C(    -5.23),
        SIMDE_FLOAT32_C(   -20.45), SIMDE_FLOAT32_C(    -8.53), SIMDE_FLOAT32_C(    17.77), SIMDE_FLOAT32_C(    42.07),
        SIMDE_FLOAT32_C(   -16.97), SIMDE_FLOAT32_C(     4.63), SIMDE_FLOAT32_C(     5.96), SIMDE_FLOAT32_C(    47.58),
        SIMDE_FLOAT32_C(   -26.44), SIMDE_FLOAT32_C(   -25.84), SIMDE_FLOAT32_C(   -39.30), SIMDE_FLOAT32_C(   -48.05) },
      UINT16_C(26554),
      { UINT16_C(52431), UINT16_C(53429), UINT16_C(20502), UINT16_C(49193), UINT16_C(52813), UINT16_C(51992), UINT16_C(20992), UINT16_C(20745),
        UINT16_C(11878), UINT16_C(18460), UINT16_C(52809), UINT16_C(19616), UINT16_C(53461), UINT16_C(20029), UINT16_C(19809), UINT16_C(52419),
        UINT16_C(20331), UINT16_C(53385), UINT16_C(52372), UINT16_C(49992), UINT16_C(20948), UINT16_C(19470), UINT16_C(20470), UINT16_C(18743),
        UINT16_C(20305), UINT16_C(18842), UINT16_C(53707), UINT16_C(52660), UINT16_C(19722), UINT16_C(53770), UINT16_C(19979), UINT16_C(53795) },
      { UINT16_C(53374), UINT16_C(18143), UINT16_C(48292), UINT16_C(51603), UINT16_C(20822), UINT16_C(49741), UINT16_C(52535), UINT16_C(50998),
        UINT16_C(53662), UINT16_C(17408), UINT16_C(53463), UINT16_C(53299), UINT16_C(52547), UINT16_C(20506), UINT16_C(49469), UINT16_C(53548),
        UINT16_C(20944), UINT16_C(20292), UINT16_C(17661), UINT16_C(20836), UINT16_C(50360), UINT16_C(51862), UINT16_C(17188), UINT16_C(52830),
        UINT16_C(20993), UINT16_C(18235), UINT16_C(16087), UINT16_C(19596), UINT16_C(18551), UINT16_C(52744), UINT16_C(19655), UINT16_C(19903) },
      { SIMDE_FLOAT32_C(   -36.63), SIMDE_FLOAT32_C(-198343328.00), SIMDE_FLOAT32_C(     1.95), SIMDE_FLOAT32_C(-26374792456997699584.00),
        SIMDE_FLOAT32_C(81788896.00), SIMDE_FLOAT32_C(23320201820477849600.00), SIMDE_FLOAT32_C(    17.77), SIMDE_FLOAT32_C(4720335359437701120.00),
        SIMDE_FLOAT32_C(379806570974663409664.00), SIMDE_FLOAT32_C(-12397708312576.00), SIMDE_FLOAT32_C(-350503691091968.00), SIMDE_FLOAT32_C(    47.58),
        SIMDE_FLOAT32_C(   -26.44), SIMDE_FLOAT32_C(-27707738117111808.00), SIMDE_FLOAT32_C(84523592990861557760.00), SIMDE_FLOAT32_C(   -48.05) } },
    { { SIMDE_FLOAT32_C(    29.97), SIMDE_FLOAT32_C(   -12.22), SIMDE_FLOAT32_C(   -23.59), SIMDE_FLOAT32_C(    29.65),
        SIMDE_FLOAT32_C(   -27.10), SIMDE_FLOAT32_C(   -47.13), SIMDE_FLOAT32_C(    16.01), SIMDE_FLOAT32_C(    -2.40),
        SIMDE_FLOAT32_C(    32.31), SIMDE_FLOAT32_C(    -3.09), SIMDE_FLOAT32_C(   -34.47), SIMDE_FLOAT32_C(    14.84),
        SIMDE_FLOAT32_C(   -16.46), SIMDE_FLOAT32_C(   -21.10), SIMDE_FLOAT32_C(    30.15), SIMDE_FLOAT32_C(    35.49) },
      UINT16_C(11773),
      { UINT16_C(20504), UINT16_C(53250), UINT16_C(53445), UINT16_C(20061), UINT16_C(19302), UINT16_C(51331), UINT16_C(53233), UINT16_C(19704),
        UINT16_C(20895), UINT16_C(52511), UINT16_C(20617), UINT16_C(52868), UINT16_C(53430), UINT16_C(52246), UINT16_C(52316), UINT16_C(53542),
        UINT16_C(53417), UINT16_C(20658), UINT16_C(53761), UINT16_C(18429), UINT16_C(52838), UINT16_C(17800), UINT16_C(20497), UINT16_C(52964),
        UINT16_C(53416), UINT16_C(52195), UINT16_C(20756), UINT16_C(19820), UINT16_C(18703), UINT16_C(18653), UINT16_C(50514), UINT16_C(50975) },
      { UINT16_C(20203), UINT16_C(18053), UINT16_C(53228), UINT16_C(51080), UINT16_C(20976), UINT16_C(51896), UINT16_C(53429), UINT16_C(20815),
        UINT16_C(19461), UINT16_C(21012), UINT16_C(53299), UINT16_C(20250), UINT16_C(52334), UINT16_C(48148), UINT16_C(20647), UINT16_C(50432),
        UINT16_C(51898), UINT16_C(20710), UINT16_C(53728), UINT16_C(18808), UINT16_C(50506), UINT16_C(20592), UINT16_C(20524), UINT16_C(18299),
        UINT16_C(53136), UINT16_C(19968), UINT16_C(52533), UINT16_C(20343), UINT16_C(52241), UINT16_C(19958), UINT16_C(52945), UINT16_C(53459) },
      { SIMDE_FLOAT32_C(20108422802627887104.00), SIMDE_FLOAT32_C(   -12.22), SIMDE_FLOAT32_C(1942178988570968064.00), SIMDE_FLOAT32_C(203676419047737524224.00),
        SIMDE_FLOAT32_C(-23518500941570506752.00), SIMDE_FLOAT32_C(-223744458987300454400.00), SIMDE_FLOAT32_C(1524046261399846912.00), SIMDE_FLOAT32_C(-1292582571078582272.00),
        SIMDE_FLOAT32_C(737647749560501534720.00), SIMDE_FLOAT32_C(    -3.09), SIMDE_FLOAT32_C(73211744092160.00), SIMDE_FLOAT32_C(112319651561317859328.00),
        SIMDE_FLOAT32_C(   -16.46), SIMDE_FLOAT32_C(-6514667967223955456.00), SIMDE_FLOAT32_C(    30.15), SIMDE_FLOAT32_C(    35.49) } },
    { { SIMDE_FLOAT32_C(   -23.04), SIMDE_FLOAT32_C(    -8.57), SIMDE_FLOAT32_C(   -48.23), SIMDE_FLOAT32_C(     9.98),
        SIMDE_FLOAT32_C(    46.06), SIMDE_FLOAT32_C(     7.73), SIMDE_FLOAT32_C(     7.56), SIMDE_FLOAT32_C(   -30.38),
        SIMDE_FLOAT32_C(    31.89), SIMDE_FLOAT32_C(    18.26), SIMDE_FLOAT32_C(   -28.43), SIMDE_FLOAT32_C(   -29.97),
        SIMDE_FLOAT32_C(    40.31), SIMDE_FLOAT32_C(   -48.46), SIMDE_FLOAT32_C(     7.81), SIMDE_FLOAT32_C(   -33.29) },
      UINT16_C(41542),
      { UINT16_C(52456), UINT16_C(51319), UINT16_C(17341), UINT16_C(52616), UINT16_C(20200), UINT16_C(19469), UINT16_C(53098), UINT16_C(50762),
        UINT16_C(19306), UINT16_C(51871), UINT16_C(52985), UINT16_C(20964), UINT16_C(20600), UINT16_C(53525), UINT16_C(51174), UINT16_C(52974),
        UINT16_C(21009), UINT16_C(50409), UINT16_C(20519), UINT16_C(50885), UINT16_C(52441), UINT16_C(19494), UINT16_C(53801), UINT16_C(13722),
        UINT16_C(51379), UINT16_C(52488), UINT16_C(52466), UINT16_C(19989), UINT16_C(53705), UINT16_C(16876), UINT16_C(20599), UINT16_C(52211) },
      { UINT16_C(20865), UINT16_C(51506), UINT16_C(18940), UINT16_C(19818), UINT16_C(53638), UINT16_C(20490), UINT16_C(53333), UINT16_C(19753),
        UINT16_C(53180), UINT16_C(51781), UINT16_C(19568), UINT16_C(53670), UINT16_C(49772), UINT16_C(53509), UINT16_C(52666), UINT16_C(50353),
        UINT16_C(17651), UINT16_C(53494), UINT16_C(20689), UINT16_C(20594), UINT16_C(20155), UINT16_C(20712), UINT16_C(51981), UINT16_C(53263),
        UINT16_C(53176), UINT16_C(19464), UINT16_C(20795), UINT16_C(52938), UINT16_C(53179), UINT16_C(20198), UINT16_C(18161), UINT16_C(53405) },
      { SIMDE_FLOAT32_C(   -23.04), SIMDE_FLOAT32_C(-69981716084686848.00), SIMDE_FLOAT32_C(-139665596459641733120.00), SIMDE_FLOAT32_C(     9.98),
        SIMDE_FLOAT32_C(    46.06), SIMDE_FLOAT32_C(     7.73), SIMDE_FLOAT32_C(1427965341049617907712.00), SIMDE_FLOAT32_C(   -30.38),
        SIMDE_FLOAT32_C(    31.89), SIMDE_FLOAT32_C(314377853375759777792.00), SIMDE_FLOAT32_C(   -28.43), SIMDE_FLOAT32_C(   -29.97),
        SIMDE_FLOAT32_C(    40.31), SIMDE_FLOAT32_C(-7427913529161678848.00), SIMDE_FLOAT32_C(     7.81), SIMDE_FLOAT32_C(671670831406907392.00) } },
    { { SIMDE_FLOAT32_C(   -30.41), SIMDE_FLOAT32_C(    -2.80), SIMDE_FLOAT32_C(   -21.69), SIMDE_FLOAT32_C(   -48.10),
        SIMDE_FLOAT32_C(    44.11), SIMDE_FLOAT32_C(    -6.16), SIMDE_FLOAT32_C(    16.74), SIMDE_FLOAT32_C(   -22.35),
        SIMDE_FLOAT32_C(    22.74), SIMDE_FLOAT32_C(    -3.11), SIMDE_FLOAT32_C(   -36.86), SIMDE_FLOAT32_C(    -3.60),
        SIMDE_FLOAT32_C(     6.59), SIMDE_FLOAT32_C(    -9.91), SIMDE_FLOAT32_C(    37.84), SIMDE_FLOAT32_C(     8.36) },
      UINT16_C(47086),
      { UINT16_C(53274), UINT16_C(53190), UINT16_C(20568), UINT16_C(52927), UINT16_C(53785), UINT16_C(53821), UINT16_C(20853), UINT16_C(53101),
        UINT16_C(51768), UINT16_C(18867), UINT16_C(52794), UINT16_C(20555), UINT16_C(19793), UINT16_C(16476), UINT16_C(52502), UINT16_C(52723),
        UINT16_C(19007), UINT16_C(53236), UINT16_C(53448), UINT16_C(51532), UINT16_C(53586), UINT16_C(49326), UINT16_C(18158), UINT16_C(52701),
        UINT16_C(53383), UINT16_C(48353), UINT16_C(47329), UINT16_C(52297), UINT16_C(52712), UINT16_C(53621), UINT16_C(50186), UINT16_C(50801) },
      { UINT16_C(52784), UINT16_C(52435), UINT16_C(19492), UINT16_C(52706), UINT16_C(52428), UINT16_C(18716), UINT16_C(49792), UINT16_C(19608),
        UINT16_C(53016), UINT16_C(19830), UINT16_C(16758), UINT16_C(20828), UINT16_C(52863), UINT16_C(20492), UINT16_C(53178), UINT16_C(20624),
        UINT16_C(53805), UINT16_C(52426), UINT16_C(52742), UINT16_C(53567), UINT16_C(20256), UINT16_C(20507), UINT16_C(52151), UINT16_C(20809),
        UINT16_C(52376), UINT16_C(20543), UINT16_C(52791), UINT16_C(18429), UINT16_C(20746), UINT16_C(19783), UINT16_C(53774), UINT16_C(53327) },
      { SIMDE_FLOAT32_C(   -30.41), SIMDE_FLOAT32_C(1382569901230653440.00), SIMDE_FLOAT32_C(17441121942852599808.00), SIMDE_FLOAT32_C(-316874646920101888.00),
        SIMDE_FLOAT32_C(    44.11), SIMDE_FLOAT32_C(804523037433465405440.00), SIMDE_FLOAT32_C(-234393854449549312.00), SIMDE_FLOAT32_C(-8867728403780861952.00),
        SIMDE_FLOAT32_C(285785062291537920.00), SIMDE_FLOAT32_C(15129900122755825664.00), SIMDE_FLOAT32_C(-151320947479648665600.00), SIMDE_FLOAT32_C(    -3.60),
        SIMDE_FLOAT32_C(1443966630525665280.00), SIMDE_FLOAT32_C(-6825374121984.00), SIMDE_FLOAT32_C(    37.84), SIMDE_FLOAT32_C(298427212627968.00) } },
    { { SIMDE_FLOAT32_C(   -33.91), SIMDE_FLOAT32_C(     7.64), SIMDE_FLOAT32_C(   -46.49), SIMDE_FLOAT32_C(    47.98),
        SIMDE_FLOAT32_C(   -24.10), SIMDE_FLOAT32_C(   -24.92), SIMDE_FLOAT32_C(   -31.98), SIMDE_FLOAT32_C(   -33.79),
        SIMDE_FLOAT32_C(   -23.38), SIMDE_FLOAT32_C(    25.83), SIMDE_FLOAT32_C(   -17.08), SIMDE_FLOAT32_C(   -42.19),
        SIMDE_FLOAT32_C(     6.54), SIMDE_FLOAT32_C(     2.51), SIMDE_FLOAT32_C(     5.01), SIMDE_FLOAT32_C(    34.85) },
      UINT16_C(47822),
      { UINT16_C(53766), UINT16_C(19592), UINT16_C(51197), UINT16_C(52311), UINT16_C(52586), UINT16_C(20696), UINT16_C(53791), UINT16_C(43295),
        UINT16_C(18765), UINT16_C(17280), UINT16_C(50982), UINT16_C(20564), UINT16_C(51950), UINT16_C(18935), UINT16_C(19784), UINT16_C(51876),
        UINT16_C(20825), UINT16_C(20961), UINT16_C(50499), UINT16_C(19794), UINT16_C(20344), UINT16_C(20307), UINT16_C(19144), UINT16_C(53456),
        UINT16_C(19107), UINT16_C(20694), UINT16_C(19679), UINT16_C(17183), UINT16_C(18664), UINT16_C(19779), UINT16_C(19655), UINT16_C(18897) },
      { UINT16_C(51564), UINT16_C(53468), UINT16_C(20873), UINT16_C(19552), UINT16_C(21052), UINT16_C(20905), UINT16_C(53265), UINT16_C(18748),
        UINT16_C(48067), UINT16_C(18728), UINT16_C(50412), UINT16_C(20581), UINT16_C(52977), UINT16_C(53306), UINT16_C(52999), UINT16_C(53344),
        UINT16_C(53400), UINT16_C(19496), UINT16_C(20617), UINT16_C(20836), UINT16_C(50194), UINT16_C(45261), UINT16_C(53676), UINT16_C(53530),
        UINT16_C(51642), UINT16_C(19974), UINT16_C(19041), UINT16_C(21004), UINT16_C(50399), UINT16_C(52360), UINT16_C(18687), UINT16_C(20553) },
      { SIMDE_FLOAT32_C(   -33.91), SIMDE_FLOAT32_C(-12837073132191744.00), SIMDE_FLOAT32_C(2580859824058700660736.00), SIMDE_FLOAT32_C(1661287830544428564480.00),
        SIMDE_FLOAT32_C(   -24.10), SIMDE_FLOAT32_C(   -24.92), SIMDE_FLOAT32_C(-9490434615148544.00), SIMDE_FLOAT32_C(-394205704883273728.00),
        SIMDE_FLOAT32_C(   -23.38), SIMDE_FLOAT32_C(13476964710301564928.00), SIMDE_FLOAT32_C(   -17.08), SIMDE_FLOAT32_C(1153469254911525912576.00),
        SIMDE_FLOAT32_C(16143145167728148480.00), SIMDE_FLOAT32_C(454901461155840.00), SIMDE_FLOAT32_C(     5.01), SIMDE_FLOAT32_C(23149177940738048.00) } },
    { { SIMDE_FLOAT32_C(   -21.30), SIMDE_FLOAT32_C(   -28.85), SIMDE_FLOAT32_C(    26.76), SIMDE_FLOAT32_C(   -48.56),
        SIMDE_FLOAT32_C(    18.04), SIMDE_FLOAT32_C(    39.90), SIMDE_FLOAT32_C(    -2.16), SIMDE_FLOAT32_C(   -25.37),
        SIMDE_FLOAT32_C(   -20.01), SIMDE_FLOAT32_C(   -14.32), SIMDE_FLOAT32_C(    32.99), SIMDE_FLOAT32_C(   -19.93),
        SIMDE_FLOAT32_C(   -30.42), SIMDE_FLOAT32_C(    49.08), SIMDE_FLOAT32_C(    37.70), SIMDE_FLOAT32_C(   -26.91) },
      UINT16_C(33422),
      { UINT16_C(50949), UINT16_C(17475), UINT16_C(16169), UINT16_C(50982), UINT16_C(46940), UINT16_C(19664), UINT16_C(53718), UINT16_C(21010),
        UINT16_C(52508), UINT16_C(48742), UINT16_C(20536), UINT16_C(16169), UINT16_C(19278), UINT16_C(53644), UINT16_C(19507), UINT16_C(20214),
        UINT16_C(19857), UINT16_C(16942), UINT16_C(19773), UINT16_C(53235), UINT16_C(53730), UINT16_C(20068), UINT16_C(52646), UINT16_C(51265),
        UINT16_C(46449), UINT16_C(20741), UINT16_C(51475), UINT16_C(20889), UINT16_C(52990), UINT16_C(21051), UINT16_C(20293), UINT16_C(19329) },
      { UINT16_C(17434), UINT16_C(52424), UINT16_C(53572), UINT16_C(53708), UINT16_C(53820), UINT16_C(53466), UINT16_C(53753), UINT16_C(52500),
        UINT16_C(18636), UINT16_C(20607), UINT16_C(20446), UINT16_C(52851), UINT16_C(20787), UINT16_C(48865), UINT16_C(53759), UINT16_C(19182),
        UINT16_C(53780), UINT16_C(19904), UINT16_C(20482), UINT16_C(53686), UINT16_C(48579), UINT16_C(53521), UINT16_C(50230), UINT16_C(20999),
        UINT16_C(21044), UINT16_C(20596), UINT16_C(20833), UINT16_C(53014), UINT16_C(20592), UINT16_C(19846), UINT16_C(20630), UINT16_C(51510) },
      { SIMDE_FLOAT32_C(   -21.30), SIMDE_FLOAT32_C(4654197823766528.00), SIMDE_FLOAT32_C(-3190800335991996416.00), SIMDE_FLOAT32_C(15334315378433056571392.00),
        SIMDE_FLOAT32_C(    18.04), SIMDE_FLOAT32_C(    39.90), SIMDE_FLOAT32_C(    -2.16), SIMDE_FLOAT32_C(-6407869104283189248.00),
        SIMDE_FLOAT32_C(   -20.01), SIMDE_FLOAT32_C(798433748524795428864.00), SIMDE_FLOAT32_C(    32.99), SIMDE_FLOAT32_C(   -19.93),
        SIMDE_FLOAT32_C(   -30.42), SIMDE_FLOAT32_C(    49.08), SIMDE_FLOAT32_C(    37.70), SIMDE_FLOAT32_C(66540671300259545088.00) } },  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m512 src, r;
    simde__m512bh a, b;

    src = simde_mm512_loadu_ps(test_vec[i].src);

    a = simde_x_mm512_castpbh_epu16(simde_x_mm512_loadu_epu16(test_vec[i].a));
    b = simde_x_mm512_castpbh_epu16(simde_x_mm512_loadu_epu16(test_vec[i].b));

    r = simde_mm512_mask_dpbf16_ps(src, test_vec[i].k, a, b);
    simde_test_x86_assert_equal_f32x16(r, simde_mm512_loadu_ps(test_vec[i].r), 1);
  }

  return 0;
#else
  fputc('\n', stdout);
  simde_bfloat16 values[8 * 2 * sizeof(simde__m512)];
  simde_test_x86_random_bf16x32_full(8, 2, values, simde_bfloat16_from_float32(-50.0f), simde_bfloat16_from_float32(50.0f), SIMDE_TEST_VEC_FLOAT_NAN);

  for (size_t i = 0 ; i < 8 ; i++) {
    simde__m512 src = simde_test_x86_random_f32x16(SIMDE_FLOAT32_C(-50.0), SIMDE_FLOAT32_C(50.0));
    simde__mmask16 k = simde_test_x86_random_mmask16();
    simde__m512bh a = simde_test_x86_random_extract_bf16x32(i, 2, 0, values);
    simde__m512bh b = simde_test_x86_random_extract_bf16x32(i, 2, 1, values);
    simde__m512 r = simde_mm512_mask_dpbf16_ps(src, k, a, b);

    simde_test_x86_write_f32x16(2, src, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_mmask16(2, k, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_u16x32(2, simde_x_mm512_castepu16_pbh(a), SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_u16x32(2, simde_x_mm512_castepu16_pbh(b), SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_f32x16(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm512_maskz_dpbf16_ps (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const simde__mmask16 k;
    const simde_float32 src[16];
    const uint16_t a[32];
    const uint16_t b[32];
    const simde_float32 r[16];
  } test_vec[] = {
    { UINT16_C( 1403),
      { SIMDE_FLOAT32_C(    31.92), SIMDE_FLOAT32_C(    -0.12), SIMDE_FLOAT32_C(    22.78), SIMDE_FLOAT32_C(   -46.66),
        SIMDE_FLOAT32_C(     8.56), SIMDE_FLOAT32_C(   -49.97), SIMDE_FLOAT32_C(    19.41), SIMDE_FLOAT32_C(    30.14),
        SIMDE_FLOAT32_C(    -2.64), SIMDE_FLOAT32_C(    26.26), SIMDE_FLOAT32_C(   -10.91), SIMDE_FLOAT32_C(    28.06),
        SIMDE_FLOAT32_C(    17.31), SIMDE_FLOAT32_C(    39.41), SIMDE_FLOAT32_C(     2.72), SIMDE_FLOAT32_C(    17.41) },
      { UINT16_C(32256), UINT16_C(19961), UINT16_C(32256), UINT16_C(53051), UINT16_C(19475), UINT16_C(53242), UINT16_C(50491), UINT16_C(53282),
        UINT16_C(52932), UINT16_C(20633), UINT16_C(53347), UINT16_C(51487), UINT16_C(53619), UINT16_C(20260), UINT16_C(52920), UINT16_C(18720),
        UINT16_C(20738), UINT16_C(19607), UINT16_C(20747), UINT16_C(53409), UINT16_C(52690), UINT16_C(16845), UINT16_C(20958), UINT16_C(50957),
        UINT16_C(50982), UINT16_C(19816), UINT16_C(52767), UINT16_C(50381), UINT16_C(52090), UINT16_C(19348), UINT16_C(20289), UINT16_C(20593) },
      { UINT16_C(51578), UINT16_C(32256), UINT16_C(32256), UINT16_C(53653), UINT16_C(18399), UINT16_C(15729), UINT16_C(52973), UINT16_C(20403),
        UINT16_C(51694), UINT16_C(51812), UINT16_C(53084), UINT16_C(50547), UINT16_C(53319), UINT16_C(50765), UINT16_C(53670), UINT16_C(53636),
        UINT16_C(53438), UINT16_C(20900), UINT16_C(53195), UINT16_C(51612), UINT16_C(49121), UINT16_C(53320), UINT16_C(20463), UINT16_C(20764),
        UINT16_C(20653), UINT16_C(53592), UINT16_C(51958), UINT16_C(52963), UINT16_C(19866), UINT16_C(53341), UINT16_C(53569), UINT16_C(53458) },
      {            SIMDE_MATH_NANF,      SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(-65297686599198310400.00),
        SIMDE_FLOAT32_C(-73505101095895040.00), SIMDE_FLOAT32_C(56227441347720642560.00), SIMDE_FLOAT32_C(871122198354276122624.00), SIMDE_FLOAT32_C(     0.00),
        SIMDE_FLOAT32_C(-882940840045147324416.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(-343158784000.00), SIMDE_FLOAT32_C(     0.00),
        SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00) } },
    { UINT16_C(48386),
      { SIMDE_FLOAT32_C(   -36.63), SIMDE_FLOAT32_C(    14.77), SIMDE_FLOAT32_C(    38.16), SIMDE_FLOAT32_C(   -10.74),
        SIMDE_FLOAT32_C(   -10.96), SIMDE_FLOAT32_C(   -47.21), SIMDE_FLOAT32_C(    46.91), SIMDE_FLOAT32_C(    32.42),
        SIMDE_FLOAT32_C(   -11.88), SIMDE_FLOAT32_C(   -10.60), SIMDE_FLOAT32_C(    39.63), SIMDE_FLOAT32_C(     0.33),
        SIMDE_FLOAT32_C(    31.96), SIMDE_FLOAT32_C(    21.55), SIMDE_FLOAT32_C(   -49.79), SIMDE_FLOAT32_C(     4.74) },
      { UINT16_C(17628), UINT16_C(53358), UINT16_C(53286), UINT16_C(53417), UINT16_C(19446), UINT16_C(51570), UINT16_C(20849), UINT16_C(53694),
        UINT16_C(20117), UINT16_C(53373), UINT16_C(48527), UINT16_C(20804), UINT16_C(18381), UINT16_C(17106), UINT16_C(20992), UINT16_C(19703),
        UINT16_C(48599), UINT16_C(53286), UINT16_C(53548), UINT16_C(20947), UINT16_C(52315), UINT16_C(20748), UINT16_C(20655), UINT16_C(53121),
        UINT16_C(20979), UINT16_C(52893), UINT16_C(51092), UINT16_C(19712), UINT16_C(51633), UINT16_C(13844), UINT16_C(20445), UINT16_C(20847) },
      { UINT16_C(19320), UINT16_C(21000), UINT16_C(53625), UINT16_C(52424), UINT16_C(51793), UINT16_C(21048), UINT16_C(52105), UINT16_C(53386),
        UINT16_C(53381), UINT16_C(20529), UINT16_C(53638), UINT16_C(19817), UINT16_C(51846), UINT16_C(53702), UINT16_C(51264), UINT16_C(20592),
        UINT16_C(53080), UINT16_C(12411), UINT16_C(20482), UINT16_C(17004), UINT16_C(51391), UINT16_C(19682), UINT16_C(19916), UINT16_C(51698),
        UINT16_C(20834), UINT16_C(53325), UINT16_C(53564), UINT16_C(52372), UINT16_C(19455), UINT16_C(20722), UINT16_C(52789), UINT16_C(52420) },
      { SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(746985611544133369856.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00),
        SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00),
        SIMDE_FLOAT32_C(380436480.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(4452956671550947328.00), SIMDE_FLOAT32_C(10057237257313583104.00),
        SIMDE_FLOAT32_C(7932636443000717705216.00), SIMDE_FLOAT32_C(-6590472696889344.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(-12222347176218460160.00) } },
    { UINT16_C(13654),
      { SIMDE_FLOAT32_C(     4.77), SIMDE_FLOAT32_C(    -5.69), SIMDE_FLOAT32_C(   -11.09), SIMDE_FLOAT32_C(   -47.87),
        SIMDE_FLOAT32_C(   -29.44), SIMDE_FLOAT32_C(    28.00), SIMDE_FLOAT32_C(    30.19), SIMDE_FLOAT32_C(    37.87),
        SIMDE_FLOAT32_C(    17.42), SIMDE_FLOAT32_C(   -17.09), SIMDE_FLOAT32_C(     5.28), SIMDE_FLOAT32_C(     2.85),
        SIMDE_FLOAT32_C(    46.80), SIMDE_FLOAT32_C(    18.65), SIMDE_FLOAT32_C(   -32.38), SIMDE_FLOAT32_C(    34.95) },
      { UINT16_C(20667), UINT16_C(52392), UINT16_C(18918), UINT16_C(52787), UINT16_C(52408), UINT16_C(20951), UINT16_C(51597), UINT16_C(50440),
        UINT16_C(20369), UINT16_C(50504), UINT16_C(53292), UINT16_C(53273), UINT16_C(48599), UINT16_C(18446), UINT16_C(53737), UINT16_C(19658),
        UINT16_C(53560), UINT16_C(20570), UINT16_C(52968), UINT16_C(48384), UINT16_C(17492), UINT16_C(20914), UINT16_C(20636), UINT16_C(49464),
        UINT16_C(53467), UINT16_C(20895), UINT16_C(20294), UINT16_C(20169), UINT16_C(20562), UINT16_C(53688), UINT16_C(53566), UINT16_C(19864) },
      { UINT16_C(52014), UINT16_C(19704), UINT16_C(20979), UINT16_C(19505), UINT16_C(19494), UINT16_C(51907), UINT16_C(53448), UINT16_C(49731),
        UINT16_C(20429), UINT16_C(52586), UINT16_C(19212), UINT16_C(52497), UINT16_C(20623), UINT16_C(19508), UINT16_C(21021), UINT16_C(20887),
        UINT16_C(15974), UINT16_C(53038), UINT16_C(50826), UINT16_C(53634), UINT16_C(53286), UINT16_C(52459), UINT16_C(17065), UINT16_C(52609),
        UINT16_C(52781), UINT16_C(52326), UINT16_C(53660), UINT16_C(53509), UINT16_C(51882), UINT16_C(53402), UINT16_C(20487), UINT16_C(19860) },
      { SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(210970992602775552.00), SIMDE_FLOAT32_C(-741750335306989568.00), SIMDE_FLOAT32_C(     0.00),
        SIMDE_FLOAT32_C(33467374730896998400.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(6859195416576.00), SIMDE_FLOAT32_C(     0.00),
        SIMDE_FLOAT32_C(-42707635266354413568.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(-11774108171411390464.00), SIMDE_FLOAT32_C(     0.00),
        SIMDE_FLOAT32_C(16181714936118902784.00), SIMDE_FLOAT32_C(-338411734999687495680.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00) } },
    { UINT16_C(14795),
      { SIMDE_FLOAT32_C(    37.74), SIMDE_FLOAT32_C(   -45.18), SIMDE_FLOAT32_C(   -10.92), SIMDE_FLOAT32_C(   -24.14),
        SIMDE_FLOAT32_C(    -5.78), SIMDE_FLOAT32_C(   -21.29), SIMDE_FLOAT32_C(    26.19), SIMDE_FLOAT32_C(   -23.82),
        SIMDE_FLOAT32_C(   -49.74), SIMDE_FLOAT32_C(    26.40), SIMDE_FLOAT32_C(    30.91), SIMDE_FLOAT32_C(    25.15),
        SIMDE_FLOAT32_C(   -14.83), SIMDE_FLOAT32_C(   -14.32), SIMDE_FLOAT32_C(   -30.54), SIMDE_FLOAT32_C(    24.08) },
      { UINT16_C(20514), UINT16_C(20340), UINT16_C(51574), UINT16_C(46490), UINT16_C(53302), UINT16_C(14991), UINT16_C(20945), UINT16_C(20976),
        UINT16_C(20299), UINT16_C(18765), UINT16_C(52656), UINT16_C(19409), UINT16_C(52646), UINT16_C(52726), UINT16_C(18732), UINT16_C(20289),
        UINT16_C(49444), UINT16_C(53702), UINT16_C(20574), UINT16_C(19232), UINT16_C(52209), UINT16_C(51677), UINT16_C(20807), UINT16_C(18615),
        UINT16_C(19756), UINT16_C(20971), UINT16_C(19666), UINT16_C(53588), UINT16_C(53487), UINT16_C(15882), UINT16_C(20331), UINT16_C(20851) },
      { UINT16_C(52396), UINT16_C(53200), UINT16_C(50885), UINT16_C(49347), UINT16_C(19685), UINT16_C(51488), UINT16_C(50401), UINT16_C(48384),
        UINT16_C(53813), UINT16_C(19864), UINT16_C(53364), UINT16_C(52623), UINT16_C(21009), UINT16_C(20013), UINT16_C(53607), UINT16_C(50189),
        UINT16_C(20257), UINT16_C(20791), UINT16_C(53498), UINT16_C(53420), UINT16_C(52480), UINT16_C(53746), UINT16_C(19844), UINT16_C(53802),
        UINT16_C(21049), UINT16_C(51284), UINT16_C(53566), UINT16_C(53494), UINT16_C(20827), UINT16_C(20663), UINT16_C(53700), UINT16_C(52854) },
      { SIMDE_FLOAT32_C(-29551213379921641472.00), SIMDE_FLOAT32_C(25408045056.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(-201974863626240.00),
        SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(-54575165642243047424.00), SIMDE_FLOAT32_C(-43687621355896832.00),
        SIMDE_FLOAT32_C(-5221869724740561666048.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(14719157762990800896.00),
        SIMDE_FLOAT32_C(35798746201084395520.00), SIMDE_FLOAT32_C(1873358396347631271936.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00) } },
    { UINT16_C(35983),
      { SIMDE_FLOAT32_C(     2.09), SIMDE_FLOAT32_C(   -31.99), SIMDE_FLOAT32_C(   -22.10), SIMDE_FLOAT32_C(   -30.50),
        SIMDE_FLOAT32_C(     0.92), SIMDE_FLOAT32_C(    33.18), SIMDE_FLOAT32_C(    22.36), SIMDE_FLOAT32_C(    -2.28),
        SIMDE_FLOAT32_C(     1.83), SIMDE_FLOAT32_C(    39.98), SIMDE_FLOAT32_C(   -17.33), SIMDE_FLOAT32_C(     9.74),
        SIMDE_FLOAT32_C(    -3.36), SIMDE_FLOAT32_C(   -29.59), SIMDE_FLOAT32_C(    14.56), SIMDE_FLOAT32_C(    35.71) },
      { UINT16_C(53617), UINT16_C(49603), UINT16_C(19826), UINT16_C(20099), UINT16_C(20636), UINT16_C(53283), UINT16_C(52813), UINT16_C(20647),
        UINT16_C(20713), UINT16_C(51562), UINT16_C(53345), UINT16_C(20665), UINT16_C(53380), UINT16_C(53007), UINT16_C(52241), UINT16_C(20812),
        UINT16_C(53392), UINT16_C(50703), UINT16_C(53663), UINT16_C(50816), UINT16_C(49981), UINT16_C(20165), UINT16_C(50639), UINT16_C(50094),
        UINT16_C(53221), UINT16_C(16502), UINT16_C(18040), UINT16_C(53464), UINT16_C(51462), UINT16_C(18734), UINT16_C(52042), UINT16_C(49961) },
      { UINT16_C(53585), UINT16_C(53594), UINT16_C(52962), UINT16_C(20875), UINT16_C(52858), UINT16_C(49531), UINT16_C(20452), UINT16_C(53396),
        UINT16_C(20622), UINT16_C(20946), UINT16_C(53787), UINT16_C(53814), UINT16_C(53228), UINT16_C(52109), UINT16_C(20823), UINT16_C(52364),
        UINT16_C(20278), UINT16_C(20983), UINT16_C(20052), UINT16_C(52786), UINT16_C(20020), UINT16_C(53152), UINT16_C(19800), UINT16_C(20839),
        UINT16_C(19823), UINT16_C(52618), UINT16_C(53681), UINT16_C(53450), UINT16_C(20678), UINT16_C(51468), UINT16_C(18445), UINT16_C(20918) },
      { SIMDE_FLOAT32_C(3629468954096392208384.00), SIMDE_FLOAT32_C(81524969695218761728.00), SIMDE_FLOAT32_C(-21955048183431168000.00), SIMDE_FLOAT32_C(-451821943766084747264.00),
        SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(-6213208267166842880.00),
        SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(-8872091265919877120.00), SIMDE_FLOAT32_C(-23079275200512.00),
        SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(-18424470175744.00) } },
    { UINT16_C( 6456),
      { SIMDE_FLOAT32_C(   -35.58), SIMDE_FLOAT32_C(   -27.54), SIMDE_FLOAT32_C(   -15.05), SIMDE_FLOAT32_C(   -35.32),
        SIMDE_FLOAT32_C(    48.86), SIMDE_FLOAT32_C(   -34.13), SIMDE_FLOAT32_C(    39.84), SIMDE_FLOAT32_C(   -15.97),
        SIMDE_FLOAT32_C(     1.55), SIMDE_FLOAT32_C(   -40.70), SIMDE_FLOAT32_C(   -41.89), SIMDE_FLOAT32_C(    39.37),
        SIMDE_FLOAT32_C(    -0.68), SIMDE_FLOAT32_C(    10.20), SIMDE_FLOAT32_C(   -42.63), SIMDE_FLOAT32_C(    27.22) },
      { UINT16_C(49608), UINT16_C(20388), UINT16_C(20737), UINT16_C(19789), UINT16_C(52619), UINT16_C(19815), UINT16_C(20563), UINT16_C(53367),
        UINT16_C(19595), UINT16_C(20600), UINT16_C(53357), UINT16_C(20624), UINT16_C(53080), UINT16_C(53591), UINT16_C(53228), UINT16_C(21039),
        UINT16_C(53663), UINT16_C(20852), UINT16_C(52820), UINT16_C(20341), UINT16_C(53404), UINT16_C(20930), UINT16_C(19907), UINT16_C(20572),
        UINT16_C(52870), UINT16_C(20195), UINT16_C(20946), UINT16_C(53436), UINT16_C(53266), UINT16_C(17577), UINT16_C(53575), UINT16_C(19270) },
      { UINT16_C(52067), UINT16_C(20987), UINT16_C(51997), UINT16_C(19080), UINT16_C(19676), UINT16_C(53098), UINT16_C(20180), UINT16_C(51762),
        UINT16_C(53629), UINT16_C(20797), UINT16_C(52858), UINT16_C(52691), UINT16_C(21030), UINT16_C(51095), UINT16_C(52724), UINT16_C(53689),
        UINT16_C(51962), UINT16_C(15094), UINT16_C(20545), UINT16_C(47759), UINT16_C(49700), UINT16_C(18202), UINT16_C(52218), UINT16_C(19765),
        UINT16_C(52142), UINT16_C(52442), UINT16_C(20510), UINT16_C(16425), UINT16_C(20584), UINT16_C(20759), UINT16_C(53292), UINT16_C(53089) },
      { SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(25230218444668928000.00),
        SIMDE_FLOAT32_C(839421571683447734272.00), SIMDE_FLOAT32_C(8125056677729796096.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00),
        SIMDE_FLOAT32_C(699289395265536000.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(2788683095191060480.00),
        SIMDE_FLOAT32_C(-192005516535267328.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00) } },
    { UINT16_C(25894),
      { SIMDE_FLOAT32_C(    10.40), SIMDE_FLOAT32_C(     2.06), SIMDE_FLOAT32_C(   -43.99), SIMDE_FLOAT32_C(   -37.77),
        SIMDE_FLOAT32_C(    -7.97), SIMDE_FLOAT32_C(   -11.33), SIMDE_FLOAT32_C(    21.96), SIMDE_FLOAT32_C(    38.67),
        SIMDE_FLOAT32_C(     9.09), SIMDE_FLOAT32_C(   -13.48), SIMDE_FLOAT32_C(    24.39), SIMDE_FLOAT32_C(   -44.64),
        SIMDE_FLOAT32_C(    -4.70), SIMDE_FLOAT32_C(    38.81), SIMDE_FLOAT32_C(   -22.18), SIMDE_FLOAT32_C(    30.25) },
      { UINT16_C(20690), UINT16_C(16589), UINT16_C(20529), UINT16_C(18429), UINT16_C(19888), UINT16_C(18799), UINT16_C(20915), UINT16_C(20277),
        UINT16_C(16778), UINT16_C(53139), UINT16_C(53647), UINT16_C(16343), UINT16_C(18958), UINT16_C(52370), UINT16_C(17966), UINT16_C(20997),
        UINT16_C(20499), UINT16_C(51428), UINT16_C(49490), UINT16_C(52511), UINT16_C(20970), UINT16_C(20441), UINT16_C(53813), UINT16_C(52355),
        UINT16_C(53440), UINT16_C(20521), UINT16_C(20545), UINT16_C(20968), UINT16_C(19969), UINT16_C(53803), UINT16_C(53256), UINT16_C(19016) },
      { UINT16_C(16937), UINT16_C(53783), UINT16_C(53085), UINT16_C(52748), UINT16_C(18962), UINT16_C(53308), UINT16_C(53675), UINT16_C(53347),
        UINT16_C(51988), UINT16_C(53498), UINT16_C(19512), UINT16_C(20990), UINT16_C(51213), UINT16_C(52924), UINT16_C(20932), UINT16_C(52833),
        UINT16_C(19108), UINT16_C(50831), UINT16_C(17403), UINT16_C(18765), UINT16_C(52811), UINT16_C(17492), UINT16_C(20818), UINT16_C(51863),
        UINT16_C(51762), UINT16_C(20134), UINT16_C(52215), UINT16_C(53452), UINT16_C(20177), UINT16_C(16189), UINT16_C(19980), UINT16_C(52458) },
      { SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(-44041901422753611776.00), SIMDE_FLOAT32_C(-11467906277703680.00), SIMDE_FLOAT32_C(     0.00),
        SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(-3703084518727483392.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00),
        SIMDE_FLOAT32_C(53014061234782208.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(-106964985953583628288.00), SIMDE_FLOAT32_C(     0.00),
        SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(-3410761208342352232448.00), SIMDE_FLOAT32_C(948605718448046080.00), SIMDE_FLOAT32_C(     0.00) } },
    { UINT16_C(18210),
      { SIMDE_FLOAT32_C(    46.12), SIMDE_FLOAT32_C(    43.33), SIMDE_FLOAT32_C(    10.71), SIMDE_FLOAT32_C(    -2.32),
        SIMDE_FLOAT32_C(   -47.37), SIMDE_FLOAT32_C(    18.82), SIMDE_FLOAT32_C(   -12.96), SIMDE_FLOAT32_C(     1.95),
        SIMDE_FLOAT32_C(   -20.98), SIMDE_FLOAT32_C(    -5.58), SIMDE_FLOAT32_C(   -20.83), SIMDE_FLOAT32_C(   -41.28),
        SIMDE_FLOAT32_C(   -47.29), SIMDE_FLOAT32_C(    39.57), SIMDE_FLOAT32_C(    10.77), SIMDE_FLOAT32_C(   -41.29) },
      { UINT16_C(16942), UINT16_C(20887), UINT16_C(17961), UINT16_C(53337), UINT16_C(53476), UINT16_C(18792), UINT16_C(52470), UINT16_C(49812),
        UINT16_C(19776), UINT16_C(20961), UINT16_C(50519), UINT16_C(53411), UINT16_C(53115), UINT16_C(51357), UINT16_C(51791), UINT16_C(20524),
        UINT16_C(20551), UINT16_C(20780), UINT16_C(50698), UINT16_C(53535), UINT16_C(50253), UINT16_C(51903), UINT16_C(50212), UINT16_C(20522),
        UINT16_C(53405), UINT16_C(20348), UINT16_C(20894), UINT16_C(20748), UINT16_C(52368), UINT16_C(19655), UINT16_C(53075), UINT16_C(20571) },
      { UINT16_C(19180), UINT16_C(20152), UINT16_C(53822), UINT16_C(20013), UINT16_C(51753), UINT16_C(52466), UINT16_C(53029), UINT16_C(53546),
        UINT16_C(52656), UINT16_C(19461), UINT16_C(53019), UINT16_C(49495), UINT16_C(53605), UINT16_C(18554), UINT16_C(52435), UINT16_C(20770),
        UINT16_C(13599), UINT16_C(20010), UINT16_C(53821), UINT16_C(20929), UINT16_C(53467), UINT16_C(50186), UINT16_C(20310), UINT16_C(52847),
        UINT16_C(52742), UINT16_C(19985), UINT16_C(53356), UINT16_C(18342), UINT16_C(50847), UINT16_C(52054), UINT16_C(51075), UINT16_C(53593) },
      { SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(-10569058820531683328.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00),
        SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(9239590338560.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00),
        SIMDE_FLOAT32_C(32921313276078325760.00), SIMDE_FLOAT32_C(-4422461087633928880128.00), SIMDE_FLOAT32_C(24106273603584.00), SIMDE_FLOAT32_C(     0.00),
        SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(-1461707293589504.00), SIMDE_FLOAT32_C(     0.00) } },  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m512 src, r;
    simde__m512bh a, b;

    src = simde_mm512_loadu_ps(test_vec[i].src);
    a = simde_x_mm512_castpbh_epu16(simde_x_mm512_loadu_epu16(test_vec[i].a));
    b = simde_x_mm512_castpbh_epu16(simde_x_mm512_loadu_epu16(test_vec[i].b));

    r = simde_mm512_maskz_dpbf16_ps(test_vec[i].k, src, a, b);
    simde_test_x86_assert_equal_f32x16(r, simde_mm512_loadu_ps(test_vec[i].r), 1);
  }

  return 0;
#else
  fputc('\n', stdout);
  simde_bfloat16 values[8 * 2 * sizeof(simde__m512)];
  simde_test_x86_random_bf16x32_full(8, 2, values, simde_bfloat16_from_float32(-50.0f), simde_bfloat16_from_float32(50.0f), SIMDE_TEST_VEC_FLOAT_NAN);

  for (size_t i = 0 ; i < 8 ; i++) {
    simde__mmask16 k = simde_test_x86_random_mmask16();
    simde__m512 src = simde_test_x86_random_f32x16(SIMDE_FLOAT32_C(-50.0), SIMDE_FLOAT32_C(50.0));
    simde__m512bh a = simde_test_x86_random_extract_bf16x32(i, 2, 0, values);
    simde__m512bh b = simde_test_x86_random_extract_bf16x32(i, 2, 1, values);
    simde__m512 r = simde_mm512_maskz_dpbf16_ps(k, src, a, b);

    simde_test_x86_write_mmask16(2, k, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_f32x16(2, src, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_u16x32(2, simde_x_mm512_castepu16_pbh(a), SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_u16x32(2, simde_x_mm512_castepu16_pbh(b), SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_f32x16(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

SIMDE_TEST_FUNC_LIST_BEGIN
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_dpbf16_ps)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_mask_dpbf16_ps)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_maskz_dpbf16_ps)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm256_dpbf16_ps)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm256_mask_dpbf16_ps)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm256_maskz_dpbf16_ps)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_dpbf16_ps)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_mask_dpbf16_ps)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_maskz_dpbf16_ps)
SIMDE_TEST_FUNC_LIST_END

#include <test/x86/avx512/test-avx512-footer.h>
