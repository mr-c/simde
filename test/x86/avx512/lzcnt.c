/* SPDX-License-Identifier: MIT
 *
 * Permission is hereby granted, free of charge, to any person
 * obtaining a copy of this software and associated documentation
 * files (the "Software"), to deal in the Software without
 * restriction, including without limitation the rights to use, copy,
 * modify, merge, publish, distribute, sublicense, and/or sell copies
 * of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be
 * included in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
 * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS
 * BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN
 * ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
 * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 *
 * Copyright:
 *   2020      Evan Nemerson <evan@nemerson.com>
 *   2025      Michael R. Crusoe <crusoe@debian.org>
 */

#define SIMDE_TEST_X86_AVX512_INSN lzcnt

#include <test/x86/avx512/test-avx512.h>
#include <simde/x86/avx512/lzcnt.h>

static int
test_simde_mm_lzcnt_epi32(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__m128i a;
    simde__m128i r;
  } test_vec[8] = {
    { simde_mm_set_epi32(           INT32_MAX,            INT32_MIN,          ~INT32_C(0), INT32_C(          0)),
      simde_mm_set_epi32(INT32_C(          1), INT32_C(          0), INT32_C(          0), INT32_C(         32)) },
    { simde_mm_set_epi32(INT32_C(        179), INT32_C(     -17551), INT32_C(   -2202065), INT32_C(    -743837)),
      simde_mm_set_epi32(INT32_C(         24), INT32_C(          0), INT32_C(          0), INT32_C(          0)) },
    { simde_mm_set_epi32(INT32_C(      -2559), INT32_C(  388806146), INT32_C(    1927808), INT32_C(       -112)),
      simde_mm_set_epi32(INT32_C(          0), INT32_C(          3), INT32_C(         11), INT32_C(          0)) },
    { simde_mm_set_epi32(INT32_C(         22), INT32_C(    -189678), INT32_C(        252), INT32_C(      27703)),
      simde_mm_set_epi32(INT32_C(         27), INT32_C(          0), INT32_C(         24), INT32_C(         17)) },
    { simde_mm_set_epi32(INT32_C(   -9106380), INT32_C(    8952567), INT32_C(         -4), INT32_C(     685169)),
      simde_mm_set_epi32(INT32_C(          0), INT32_C(          8), INT32_C(          0), INT32_C(         12)) },
    { simde_mm_set_epi32(INT32_C(     267298), INT32_C(      -3422), INT32_C(          4), INT32_C(      31229)),
      simde_mm_set_epi32(INT32_C(         13), INT32_C(          0), INT32_C(         29), INT32_C(         17)) },
    { simde_mm_set_epi32(INT32_C(     167383), INT32_C(        214), INT32_C(          0), INT32_C(     -20257)),
      simde_mm_set_epi32(INT32_C(         14), INT32_C(         24), INT32_C(         32), INT32_C(          0)) },
    { simde_mm_set_epi32(INT32_C(       -147), INT32_C(   -1774263), INT32_C(     143922), INT32_C(    -914728)),
      simde_mm_set_epi32(INT32_C(          0), INT32_C(          0), INT32_C(         14), INT32_C(          0)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128i r = simde_mm_lzcnt_epi32(test_vec[i].a);
    simde_assert_m128i_i32(r, ==, test_vec[i].r);
  }

  return 0;
}

static int
test_simde_mm_mask_lzcnt_epi32 (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    const int32_t src[4];
    const simde__mmask8 k;
    const int32_t a[4];
    const int32_t r[4];
  } test_vec[] = {
    { { -INT32_C(  1967906480),  INT32_C(   444241631),  INT32_C(  1751328815),  INT32_C(  1797987849) },
      UINT8_C( 10),
      {  INT32_C(     5428843),  INT32_C(   517032875),  INT32_C(   698580121),  INT32_C(   725459874) },
      { -INT32_C(  1967906480),  INT32_C(           3),  INT32_C(  1751328815),  INT32_C(           2) } },
    { { -INT32_C(    69694592),  INT32_C(   153290917), -INT32_C(  1675154320), -INT32_C(   246713960) },
      UINT8_C( 13),
      {  INT32_C(       18677),  INT32_C(       21570),  INT32_C(       30363),  INT32_C(        9014) },
      {  INT32_C(          17),  INT32_C(   153290917),  INT32_C(          17),  INT32_C(          18) } },
    { { -INT32_C(  1957041304),  INT32_C(   481872372), -INT32_C(  1332916123), -INT32_C(   503559615) },
      UINT8_C(  6),
      {  INT32_C(           0),  INT32_C(           6),  INT32_C(           6),  INT32_C(           0) },
      { -INT32_C(  1957041304),  INT32_C(          29),  INT32_C(          29), -INT32_C(   503559615) } },
    { { -INT32_C(  2084109621), -INT32_C(  1412223970), -INT32_C(   638184227), -INT32_C(   244896523) },
      UINT8_C(  2),
      {  INT32_C(      315764),  INT32_C(      402356),  INT32_C(      357196),  INT32_C(      345035) },
      { -INT32_C(  2084109621),  INT32_C(          13), -INT32_C(   638184227), -INT32_C(   244896523) } },
    { { -INT32_C(   816134404),  INT32_C(  1743009649),  INT32_C(  2022955280),  INT32_C(  1643201995) },
      UINT8_C(  4),
      {  INT32_C(        4198),  INT32_C(      523483),  INT32_C(      334642),  INT32_C(      359676) },
      { -INT32_C(   816134404),  INT32_C(  1743009649),  INT32_C(          13),  INT32_C(  1643201995) } },
    { {  INT32_C(  1394876527),  INT32_C(   455882120), -INT32_C(  1637746771),  INT32_C(   707450200) },
      UINT8_C(  1),
      {  INT32_C(      820684),  INT32_C(      155800),  INT32_C(      822191),  INT32_C(      791418) },
      {  INT32_C(          12),  INT32_C(   455882120), -INT32_C(  1637746771),  INT32_C(   707450200) } },
    { { -INT32_C(  1241429622), -INT32_C(   961630619),  INT32_C(  2006648396), -INT32_C(   224101327) },
      UINT8_C(  8),
      {  INT32_C(    15383396),  INT32_C(    19320589),  INT32_C(    17462288),  INT32_C(     2498061) },
      { -INT32_C(  1241429622), -INT32_C(   961630619),  INT32_C(  2006648396),  INT32_C(          10) } },
    { {  INT32_C(  1941272773), -INT32_C(   646315458),  INT32_C(   492153721),  INT32_C(  1334390173) },
      UINT8_C( 10),
      {  INT32_C(          50),  INT32_C(         123),  INT32_C(         121),  INT32_C(          96) },
      {  INT32_C(  1941272773),  INT32_C(          25),  INT32_C(   492153721),  INT32_C(          25) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m128i src = simde_x_mm_loadu_epi32(test_vec[i].src);
    simde__m128i a = simde_x_mm_loadu_epi32(test_vec[i].a);
    simde__m128i r = simde_mm_mask_lzcnt_epi32(src, test_vec[i].k, a);
    simde_test_x86_assert_equal_i32x4(r, simde_x_mm_loadu_epi32(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_mm_maskz_lzcnt_epi32 (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    const simde__mmask8 k;
    const int32_t a[16];
    const int32_t r[16];
  } test_vec[] = {
    { UINT8_C( 11),
      {  INT32_C(           6),  INT32_C(           2),  INT32_C(           1),  INT32_C(           7) },
      {  INT32_C(          29),  INT32_C(          30),  INT32_C(           0),  INT32_C(          29) } },
    { UINT8_C(  1),
      {  INT32_C(    57768613),  INT32_C(    44212542),  INT32_C(   220122657),  INT32_C(   188272304) },
      {  INT32_C(           6),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0) } },
    { UINT8_C(  1),
      {  INT32_C(       15428),  INT32_C(        3147),  INT32_C(         201),  INT32_C(       13035) },
      {  INT32_C(          18),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0) } },
    { UINT8_C( 14),
      {  INT32_C(        7895),  INT32_C(        6520),  INT32_C(        2703),  INT32_C(        1256) },
      {  INT32_C(           0),  INT32_C(          19),  INT32_C(          20),  INT32_C(          21) } },
    { UINT8_C( 18),
      {  INT32_C(     3584232),  INT32_C(     3831674),  INT32_C(      372002),  INT32_C(     3456164) },
      {  INT32_C(           0),  INT32_C(          10),  INT32_C(           0),  INT32_C(           0) } },
    { UINT8_C( 16),
      {  INT32_C(        1915),  INT32_C(       47708),  INT32_C(       61410),  INT32_C(       63376) },
      {  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0) } },
    { UINT8_C(  4),
      {  INT32_C(   576116464),  INT32_C(   682438940),  INT32_C(  1066509946),  INT32_C(  1013501310) },
      {  INT32_C(           0),  INT32_C(           0),  INT32_C(           2),  INT32_C(           0) } },
    { UINT8_C( 22),
      {  INT32_C(      121955),  INT32_C(      108474),  INT32_C(      112020),  INT32_C(      114447) },
      {  INT32_C(           0),  INT32_C(          15),  INT32_C(          15),  INT32_C(           0) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m128i a = simde_x_mm_loadu_epi32(test_vec[i].a);
    simde__m128i r = simde_mm_maskz_lzcnt_epi32(test_vec[i].k, a);
    simde_test_x86_assert_equal_i32x4(r, simde_x_mm_loadu_epi32(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_mm256_lzcnt_epi32(SIMDE_MUNIT_TEST_ARGS) {
#if 1
  const struct {
    const int32_t a[8];
    const int32_t r[8];
  } test_vec[] = {
    { { -INT32_C(  1470193164), -INT32_C(  1522785582),  INT32_C(  1783650673), -INT32_C(  1717921740), -INT32_C(   164695212),  INT32_C(  1974442982),  INT32_C(   947532375),  INT32_C(   319981342) },
      {  INT32_C(           0),  INT32_C(           0),  INT32_C(           1),  INT32_C(           0),  INT32_C(           0),  INT32_C(           1),  INT32_C(           2),  INT32_C(           3) } },
    { { -INT32_C(    71602136),  INT32_C(    77658002), -INT32_C(  2056327088), -INT32_C(   585234295), -INT32_C(   506245893),  INT32_C(  1062699751), -INT32_C(   747122252), -INT32_C(  2115597992) },
      {  INT32_C(           0),  INT32_C(           5),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           2),  INT32_C(           0),  INT32_C(           0) } },
    { { -INT32_C(  1954766343), -INT32_C(   376496999), -INT32_C(  1787888372),  INT32_C(    24284421), -INT32_C(  1042135335),  INT32_C(  2097166792),  INT32_C(  1666217739), -INT32_C(   102484480) },
      {  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           7),  INT32_C(           0),  INT32_C(           1),  INT32_C(           1),  INT32_C(           0) } },
    { {  INT32_C(  1887723735), -INT32_C(  1990585220),  INT32_C(   387893265),  INT32_C(   790139221), -INT32_C(  1611597097),  INT32_C(  1058861108),  INT32_C(  1738697831),  INT32_C(  2053146530) },
      {  INT32_C(           1),  INT32_C(           0),  INT32_C(           3),  INT32_C(           2),  INT32_C(           0),  INT32_C(           2),  INT32_C(           1),  INT32_C(           1) } },
    { {  INT32_C(  1693115623),  INT32_C(   183321848),  INT32_C(  1646332685),  INT32_C(  1938897308),  INT32_C(  1729331507), -INT32_C(   660197519),  INT32_C(  1044335004), -INT32_C(  1212637232) },
      {  INT32_C(           1),  INT32_C(           4),  INT32_C(           1),  INT32_C(           1),  INT32_C(           1),  INT32_C(           0),  INT32_C(           2),  INT32_C(           0) } },
    { {  INT32_C(  2082186116), -INT32_C(   192542489), -INT32_C(  1336432876),  INT32_C(   337963232), -INT32_C(   612681878),  INT32_C(    45359718),  INT32_C(   994177899),  INT32_C(   401799571) },
      {  INT32_C(           1),  INT32_C(           0),  INT32_C(           0),  INT32_C(           3),  INT32_C(           0),  INT32_C(           6),  INT32_C(           2),  INT32_C(           3) } },
    { { -INT32_C(  2070737252),  INT32_C(   712514070), -INT32_C(  1562652735),  INT32_C(   582418360), -INT32_C(  1661128394), -INT32_C(  1096830637),  INT32_C(   955900069),  INT32_C(  1984949465) },
      {  INT32_C(           0),  INT32_C(           2),  INT32_C(           0),  INT32_C(           2),  INT32_C(           0),  INT32_C(           0),  INT32_C(           2),  INT32_C(           1) } },
    { {  INT32_C(   284877562), -INT32_C(  1103400196), -INT32_C(    94366142),  INT32_C(  1260131861), -INT32_C(  1679353529),  INT32_C(  1884915403),  INT32_C(  1084773222),  INT32_C(   968292159) },
      {  INT32_C(           3),  INT32_C(           0),  INT32_C(           0),  INT32_C(           1),  INT32_C(           0),  INT32_C(           1),  INT32_C(           1),  INT32_C(           2) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m256i a = simde_mm256_loadu_epi32(test_vec[i].a);
    simde__m256i r = simde_mm256_lzcnt_epi32(a);
    simde_test_x86_assert_equal_i32x8(r, simde_mm256_loadu_epi32(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m256i a = simde_test_x86_random_i32x8();
    simde__m256i r = simde_mm256_lzcnt_epi32(a);

    simde_test_x86_write_i32x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i32x8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm256_mask_lzcnt_epi32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  const struct {
    const int32_t src[8];
    const simde__mmask8 k;
    const int32_t a[8];
    const int32_t r[8];
  } test_vec[] = {
    { { -INT32_C(   699813671),  INT32_C(  1687454754), -INT32_C(  1352731494),  INT32_C(  1375369738),  INT32_C(  1609360020), -INT32_C(   808499608), -INT32_C(   670074983),  INT32_C(  1192346990) },
      UINT8_C( 16),
      { -INT32_C(  1759683979),  INT32_C(  2046603743), -INT32_C(  1356244315),  INT32_C(  1761682389),  INT32_C(  1858661637), -INT32_C(   868378829),  INT32_C(  2091142158), -INT32_C(  2033994479) },
      { -INT32_C(   699813671),  INT32_C(  1687454754), -INT32_C(  1352731494),  INT32_C(  1375369738),  INT32_C(           1), -INT32_C(   808499608), -INT32_C(   670074983),  INT32_C(  1192346990) } },
    { { -INT32_C(  1829823007),  INT32_C(  1949853721), -INT32_C(  1253447791), -INT32_C(   692407576),  INT32_C(   285812858), -INT32_C(  1323313563),  INT32_C(   818060154),  INT32_C(  1061177438) },
      UINT8_C(169),
      {  INT32_C(  2144481126),  INT32_C(   703793815), -INT32_C(   622969615),  INT32_C(  1756403950),  INT32_C(   645511617),  INT32_C(   181966991), -INT32_C(  1841653197),  INT32_C(  1238465251) },
      {  INT32_C(           1),  INT32_C(  1949853721), -INT32_C(  1253447791),  INT32_C(           1),  INT32_C(   285812858),  INT32_C(           4),  INT32_C(   818060154),  INT32_C(           1) } },
    { { -INT32_C(  1388263261), -INT32_C(   123770436), -INT32_C(   521701049), -INT32_C(   492744919),  INT32_C(  1634912201),  INT32_C(   982875295),  INT32_C(   807217078), -INT32_C(  1663473928) },
      UINT8_C( 51),
      { -INT32_C(   364308178), -INT32_C(   891033469), -INT32_C(  1968518559), -INT32_C(   496153831), -INT32_C(  1304109293),  INT32_C(   300734811), -INT32_C(   129955584), -INT32_C(  1634461073) },
      {  INT32_C(           0),  INT32_C(           0), -INT32_C(   521701049), -INT32_C(   492744919),  INT32_C(           0),  INT32_C(           3),  INT32_C(   807217078), -INT32_C(  1663473928) } },
    { { -INT32_C(   961115938),  INT32_C(   891847019),  INT32_C(  2001711659), -INT32_C(    24497889),  INT32_C(  1314471029),  INT32_C(   843999785), -INT32_C(   979220565), -INT32_C(  1174847269) },
      UINT8_C( 86),
      {  INT32_C(   880848840),  INT32_C(  1550428208),  INT32_C(  2060695642),  INT32_C(  1601723882), -INT32_C(  1028730215), -INT32_C(   386532292),  INT32_C(   531470147), -INT32_C(  1613191465) },
      { -INT32_C(   961115938),  INT32_C(           1),  INT32_C(           1), -INT32_C(    24497889),  INT32_C(           0),  INT32_C(   843999785),  INT32_C(           3), -INT32_C(  1174847269) } },
    { {  INT32_C(     8835928), -INT32_C(   178527683),  INT32_C(   316659125),  INT32_C(   531382093), -INT32_C(   379818259), -INT32_C(    97696669), -INT32_C(  1731113743),  INT32_C(  2112778532) },
      UINT8_C(166),
      { -INT32_C(  2122484668),  INT32_C(   209180759), -INT32_C(    81832275), -INT32_C(  2112173163), -INT32_C(  1653836231), -INT32_C(  1399350854),  INT32_C(   155478501),  INT32_C(   512111322) },
      {  INT32_C(     8835928),  INT32_C(           4),  INT32_C(           0),  INT32_C(   531382093), -INT32_C(   379818259),  INT32_C(           0), -INT32_C(  1731113743),  INT32_C(           3) } },
    { { -INT32_C(   587358204),  INT32_C(  1837763095), -INT32_C(   201095895),  INT32_C(   372082079), -INT32_C(  1966028047), -INT32_C(   881886110), -INT32_C(   224036416),  INT32_C(    60408831) },
      UINT8_C(212),
      {  INT32_C(  2061538915), -INT32_C(   907515232), -INT32_C(  1900155921),  INT32_C(  1654975344),  INT32_C(   401372597), -INT32_C(  1293787919), -INT32_C(   727414827), -INT32_C(  1361560245) },
      { -INT32_C(   587358204),  INT32_C(  1837763095),  INT32_C(           0),  INT32_C(   372082079),  INT32_C(           3), -INT32_C(   881886110),  INT32_C(           0),  INT32_C(           0) } },
    { {  INT32_C(   578038200), -INT32_C(    65978863), -INT32_C(   429088773), -INT32_C(  1180905916),  INT32_C(   397063099),  INT32_C(   502029462),  INT32_C(  1047052289),  INT32_C(  1343362968) },
      UINT8_C(  0),
      {  INT32_C(  1366460224), -INT32_C(  1068661819),  INT32_C(  1739045155),  INT32_C(  1126187912), -INT32_C(  1940206858),  INT32_C(   682247719), -INT32_C(  1620700666),  INT32_C(  1777301801) },
      {  INT32_C(   578038200), -INT32_C(    65978863), -INT32_C(   429088773), -INT32_C(  1180905916),  INT32_C(   397063099),  INT32_C(   502029462),  INT32_C(  1047052289),  INT32_C(  1343362968) } },
    { { -INT32_C(   440026526), -INT32_C(  1056406265),  INT32_C(  1867083564),  INT32_C(  1516670095),  INT32_C(   746713830), -INT32_C(  1355634276), -INT32_C(  1999056625),  INT32_C(   596132545) },
      UINT8_C(  2),
      {  INT32_C(    67653116), -INT32_C(     3862061),  INT32_C(   275713664), -INT32_C(  2140482150),  INT32_C(  1689054151), -INT32_C(  1558978924),  INT32_C(  1898769328),  INT32_C(   714388525) },
      { -INT32_C(   440026526),  INT32_C(           0),  INT32_C(  1867083564),  INT32_C(  1516670095),  INT32_C(   746713830), -INT32_C(  1355634276), -INT32_C(  1999056625),  INT32_C(   596132545) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m256i src = simde_mm256_loadu_epi32(test_vec[i].src);
    simde__m256i a = simde_mm256_loadu_epi32(test_vec[i].a);
    simde__m256i r = simde_mm256_mask_lzcnt_epi32(src, test_vec[i].k, a);
    simde_test_x86_assert_equal_i32x8(r, simde_mm256_loadu_epi32(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m256i src = simde_test_x86_random_i32x8();
    simde__m256i a = simde_test_x86_random_i32x8();
    simde__mmask8 k = simde_test_x86_random_mmask8();
    simde__m256i r = simde_mm256_mask_lzcnt_epi32(src, k, a);

    simde_test_x86_write_i32x8(2, src, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_mmask8(2, k, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i32x8(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i32x8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm256_maskz_lzcnt_epi32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  const struct {
    const simde__mmask8 k;
    const int32_t a[8];
    const int32_t r[8];
  } test_vec[] = {
    { UINT8_C(200),
      { -INT32_C(  1378537828),  INT32_C(    19846387),  INT32_C(   412827203), -INT32_C(  1814029400), -INT32_C(  1524153145),  INT32_C(  1112918615), -INT32_C(  1418672394), -INT32_C(   139617702) },
      {  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0) } },
    { UINT8_C(240),
      {  INT32_C(  1455137922),  INT32_C(   278576338),  INT32_C(  1924706903), -INT32_C(   700888174),  INT32_C(  1026416242), -INT32_C(    97292236),  INT32_C(  2052447968),  INT32_C(   222448779) },
      {  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           2),  INT32_C(           0),  INT32_C(           1),  INT32_C(           4) } },
    { UINT8_C(150),
      { -INT32_C(  1178376963), -INT32_C(  1341074434), -INT32_C(   683441524), -INT32_C(  1723196997), -INT32_C(  1211267257), -INT32_C(  1718105926),  INT32_C(  1763971357),  INT32_C(  1348022867) },
      {  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           1) } },
    { UINT8_C(243),
      { -INT32_C(   258733796), -INT32_C(  1686354919), -INT32_C(  1588178041),  INT32_C(   619245469), -INT32_C(  2048942147),  INT32_C(  1201829942), -INT32_C(   828765284), -INT32_C(  2124092828) },
      {  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           1),  INT32_C(           0),  INT32_C(           0) } },
    { UINT8_C( 50),
      {  INT32_C(  1024225784),  INT32_C(  1086629869), -INT32_C(   320969219), -INT32_C(   324468147),  INT32_C(  1495412449), -INT32_C(   604608048), -INT32_C(   314522621),  INT32_C(   568377641) },
      {  INT32_C(           0),  INT32_C(           1),  INT32_C(           0),  INT32_C(           0),  INT32_C(           1),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0) } },
    { UINT8_C(222),
      { -INT32_C(  1826660628), -INT32_C(  2003804381),  INT32_C(  1087798589),  INT32_C(  1428275750),  INT32_C(  1311079397),  INT32_C(   894566769),  INT32_C(    39731009),  INT32_C(   204767264) },
      {  INT32_C(           0),  INT32_C(           0),  INT32_C(           1),  INT32_C(           1),  INT32_C(           1),  INT32_C(           0),  INT32_C(           6),  INT32_C(           4) } },
    { UINT8_C(180),
      { -INT32_C(  1308516269), -INT32_C(  1376744912),  INT32_C(   584331360), -INT32_C(   871945903),  INT32_C(  1329419854), -INT32_C(   409963608),  INT32_C(  1359450833),  INT32_C(   422581446) },
      {  INT32_C(           0),  INT32_C(           0),  INT32_C(           2),  INT32_C(           0),  INT32_C(           1),  INT32_C(           0),  INT32_C(           0),  INT32_C(           3) } },
    { UINT8_C(252),
      { -INT32_C(  1142633423), -INT32_C(   333737284), -INT32_C(  1891811738), -INT32_C(  1680012731), -INT32_C(  1170002617),  INT32_C(  1351363517),  INT32_C(  1175903538),  INT32_C(  1073360909) },
      {  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           1),  INT32_C(           1),  INT32_C(           2) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m256i a = simde_mm256_loadu_epi32(test_vec[i].a);
    simde__m256i r = simde_mm256_maskz_lzcnt_epi32(test_vec[i].k, a);
    simde_test_x86_assert_equal_i32x8(r, simde_mm256_loadu_epi32(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m256i a = simde_test_x86_random_i32x8();
    simde__mmask8 k = simde_test_x86_random_mmask8();
    simde__m256i r = simde_mm256_maskz_lzcnt_epi32( k, a);

    simde_test_x86_write_mmask8(2, k, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i32x8(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i32x8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm512_lzcnt_epi32(SIMDE_MUNIT_TEST_ARGS) {
#if 1
  const struct {
    const int32_t a[16];
    const int32_t r[16];
  } test_vec[] = {
    { {  INT32_C(  1907948255),  INT32_C(  1423418390), -INT32_C(   342268191),  INT32_C(  1882404163), -INT32_C(  1557205640),  INT32_C(  1473674873), -INT32_C(  1000072044), -INT32_C(   155147497),
        -INT32_C(  1268287330), -INT32_C(    33014244), -INT32_C(   404119132),  INT32_C(  1331174614), -INT32_C(  2081257974), -INT32_C(  1730492412), -INT32_C(    60997659), -INT32_C(  2131616286) },
      {  INT32_C(           1),  INT32_C(           1),  INT32_C(           0),  INT32_C(           1),  INT32_C(           0),  INT32_C(           1),  INT32_C(           0),  INT32_C(           0),
         INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           1),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0) } },
    { { -INT32_C(  1305192042),  INT32_C(  1001405591), -INT32_C(  1272800546), -INT32_C(  1073513802),  INT32_C(    71628288), -INT32_C(  1549984066),  INT32_C(  1084226141), -INT32_C(  1379888873),
        -INT32_C(  2124352022),  INT32_C(   263983153),  INT32_C(  1640292266),  INT32_C(  1512163161),  INT32_C(  2086561213), -INT32_C(   517997692),  INT32_C(   220315637),  INT32_C(  1002103376) },
      {  INT32_C(           0),  INT32_C(           2),  INT32_C(           0),  INT32_C(           0),  INT32_C(           5),  INT32_C(           0),  INT32_C(           1),  INT32_C(           0),
         INT32_C(           0),  INT32_C(           4),  INT32_C(           1),  INT32_C(           1),  INT32_C(           1),  INT32_C(           0),  INT32_C(           4),  INT32_C(           2) } },
    { {  INT32_C(   146545367), -INT32_C(   719816405), -INT32_C(  1321804712),  INT32_C(  1628133539),  INT32_C(  1105029821),  INT32_C(  1529085029),  INT32_C(   208159931), -INT32_C(    45669850),
         INT32_C(  1745224509), -INT32_C(   734192004), -INT32_C(  1652132614), -INT32_C(  1979805236),  INT32_C(  1640750075), -INT32_C(  1816334632),  INT32_C(  1503601714), -INT32_C(  2091456954) },
      {  INT32_C(           4),  INT32_C(           0),  INT32_C(           0),  INT32_C(           1),  INT32_C(           1),  INT32_C(           1),  INT32_C(           4),  INT32_C(           0),
         INT32_C(           1),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           1),  INT32_C(           0),  INT32_C(           1),  INT32_C(           0) } },
    { {  INT32_C(  1726700778),  INT32_C(  1950034298),  INT32_C(  1762836893),  INT32_C(  1324486738), -INT32_C(   995115540), -INT32_C(   564696149), -INT32_C(   717752433), -INT32_C(   950432291),
         INT32_C(  1680753898),  INT32_C(   182020461),  INT32_C(  2087971626), -INT32_C(   406165765), -INT32_C(   810845917),  INT32_C(  1940718564), -INT32_C(   683023110),  INT32_C(  1537188465) },
      {  INT32_C(           1),  INT32_C(           1),  INT32_C(           1),  INT32_C(           1),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),
         INT32_C(           1),  INT32_C(           4),  INT32_C(           1),  INT32_C(           0),  INT32_C(           0),  INT32_C(           1),  INT32_C(           0),  INT32_C(           1) } },
    { {  INT32_C(  1421921766),  INT32_C(  1616812342),  INT32_C(  2145178244),  INT32_C(  1533519672),  INT32_C(    86643232),  INT32_C(   259577621),  INT32_C(   770163131),  INT32_C(  1250461283),
        -INT32_C(  1986115501),  INT32_C(  1709833441),  INT32_C(   115721678), -INT32_C(  1922937748),  INT32_C(  1955761246),  INT32_C(   528681572),  INT32_C(   793537228),  INT32_C(  1132058096) },
      {  INT32_C(           1),  INT32_C(           1),  INT32_C(           1),  INT32_C(           1),  INT32_C(           5),  INT32_C(           4),  INT32_C(           2),  INT32_C(           1),
         INT32_C(           0),  INT32_C(           1),  INT32_C(           5),  INT32_C(           0),  INT32_C(           1),  INT32_C(           3),  INT32_C(           2),  INT32_C(           1) } },
    { { -INT32_C(     3401955), -INT32_C(   496716524), -INT32_C(   404141701), -INT32_C(   193705067),  INT32_C(   996673239), -INT32_C(   581178607),  INT32_C(  1175234390), -INT32_C(  1702197636),
        -INT32_C(  1315350883), -INT32_C(  2020279028), -INT32_C(   596738745), -INT32_C(  1613700152), -INT32_C(    86296343),  INT32_C(  2060924452),  INT32_C(  1522590941),  INT32_C(   133450346) },
      {  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           2),  INT32_C(           0),  INT32_C(           1),  INT32_C(           0),
         INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           1),  INT32_C(           1),  INT32_C(           5) } },
    { { -INT32_C(  1380348511), -INT32_C(   785101430), -INT32_C(  1834048822),  INT32_C(  1865514629), -INT32_C(   613872457),  INT32_C(   542458178), -INT32_C(  1887824603),  INT32_C(    26635872),
        -INT32_C(  2052173829),  INT32_C(  1717035676),  INT32_C(   184026500),  INT32_C(   981019267),  INT32_C(  2031477302),  INT32_C(  1218013731), -INT32_C(   522775680),  INT32_C(  2095148673) },
      {  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           1),  INT32_C(           0),  INT32_C(           2),  INT32_C(           0),  INT32_C(           7),
         INT32_C(           0),  INT32_C(           1),  INT32_C(           4),  INT32_C(           2),  INT32_C(           1),  INT32_C(           1),  INT32_C(           0),  INT32_C(           1) } },
    { {  INT32_C(  1510051773), -INT32_C(   171943823), -INT32_C(   503334563),  INT32_C(   421230819),  INT32_C(  2123510107),  INT32_C(   466037659), -INT32_C(  1074028994), -INT32_C(   902046708),
        -INT32_C(   601604757), -INT32_C(   204282731), -INT32_C(  2133536355), -INT32_C(  1516572854), -INT32_C(  1138545632), -INT32_C(  1764234664), -INT32_C(  1789471863),  INT32_C(   459248047) },
      {  INT32_C(           1),  INT32_C(           0),  INT32_C(           0),  INT32_C(           3),  INT32_C(           1),  INT32_C(           3),  INT32_C(           0),  INT32_C(           0),
         INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           3) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m512i a = simde_mm512_loadu_epi32(test_vec[i].a);
    simde__m512i r = simde_mm512_lzcnt_epi32(a);
    simde_test_x86_assert_equal_i32x16(r, simde_mm512_loadu_epi32(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m512i a = simde_test_x86_random_i32x16();
    simde__m512i r = simde_mm512_lzcnt_epi32(a);

    simde_test_x86_write_i32x16(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i32x16(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm512_mask_lzcnt_epi32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  const struct {
    const int32_t src[16];
    const simde__mmask16 k;
    const int32_t a[16];
    const int32_t r[16];
  } test_vec[] = {
    { {  INT32_C(  1693942734),  INT32_C(    89639272), -INT32_C(   444191845),  INT32_C(   998907930), -INT32_C(  1527272116),  INT32_C(   557567640),  INT32_C(  1370919329), -INT32_C(   244574686),
         INT32_C(    22373273), -INT32_C(   939021267), -INT32_C(   240284201), -INT32_C(   114542675),  INT32_C(  2090738660), -INT32_C(  1818371598), -INT32_C(  1931193238),  INT32_C(    58544234) },
      UINT16_C( 1573),
      { -INT32_C(   519712076),  INT32_C(  1437142142),  INT32_C(  1179080345),  INT32_C(  1899983757), -INT32_C(  1980834409),  INT32_C(   538741686),  INT32_C(  1236074975),  INT32_C(    88943185),
         INT32_C(  2078692093), -INT32_C(   137261218),  INT32_C(  1916606693),  INT32_C(   585399435),  INT32_C(   279695962),  INT32_C(  1026672733),  INT32_C(   445046473),  INT32_C(    86037256) },
      {  INT32_C(           0),  INT32_C(    89639272),  INT32_C(           1),  INT32_C(   998907930), -INT32_C(  1527272116),  INT32_C(           2),  INT32_C(  1370919329), -INT32_C(   244574686),
         INT32_C(    22373273),  INT32_C(           0),  INT32_C(           1), -INT32_C(   114542675),  INT32_C(  2090738660), -INT32_C(  1818371598), -INT32_C(  1931193238),  INT32_C(    58544234) } },
    { {  INT32_C(  1385595777), -INT32_C(  1217758342), -INT32_C(   768281106), -INT32_C(  1012625896), -INT32_C(   812973666), -INT32_C(   978496450), -INT32_C(  1885817233),  INT32_C(  1016446651),
        -INT32_C(  1131533503), -INT32_C(  1787561817),  INT32_C(   107456494), -INT32_C(   725021899),  INT32_C(  1268995340),  INT32_C(   403722665), -INT32_C(  1029199865), -INT32_C(  1459667610) },
      UINT16_C(24334),
      {  INT32_C(   258248040),  INT32_C(  1956960134), -INT32_C(  1267070081),  INT32_C(   596132630),  INT32_C(  1114516632), -INT32_C(  2074444163), -INT32_C(  1924791770), -INT32_C(  1489681089),
         INT32_C(  1505204691), -INT32_C(   271754384),  INT32_C(  2107918183),  INT32_C(   597699722), -INT32_C(   714797480), -INT32_C(  1285963892),  INT32_C(     4235457), -INT32_C(  1196919323) },
      {  INT32_C(  1385595777),  INT32_C(           1),  INT32_C(           0),  INT32_C(           2), -INT32_C(   812973666), -INT32_C(   978496450), -INT32_C(  1885817233),  INT32_C(  1016446651),
         INT32_C(           1),  INT32_C(           0),  INT32_C(           1),  INT32_C(           2),  INT32_C(           0),  INT32_C(   403722665),  INT32_C(           9), -INT32_C(  1459667610) } },
    { { -INT32_C(   558203375),  INT32_C(   304423278),  INT32_C(  1061073055),  INT32_C(   944674771), -INT32_C(   956835220), -INT32_C(   848905843),  INT32_C(  1631734713),  INT32_C(   364924932),
         INT32_C(  1039432655),  INT32_C(   995039644), -INT32_C(  1669624375), -INT32_C(  1848325852),  INT32_C(   827837603),  INT32_C(  1056882053),  INT32_C(   211829000),  INT32_C(  1612865681) },
      UINT16_C(22937),
      {  INT32_C(  2023560923), -INT32_C(   105649105), -INT32_C(  1634390406), -INT32_C(  1691391241), -INT32_C(  1144224202),  INT32_C(  1291438659), -INT32_C(  1655138037), -INT32_C(   704808198),
        -INT32_C(  1068655728),  INT32_C(    28901767),  INT32_C(   664817199), -INT32_C(   289222728), -INT32_C(  1716941226),  INT32_C(  1692771160),  INT32_C(   906051132),  INT32_C(  1225588408) },
      {  INT32_C(           1),  INT32_C(   304423278),  INT32_C(  1061073055),  INT32_C(           0),  INT32_C(           0), -INT32_C(   848905843),  INT32_C(  1631734713),  INT32_C(           0),
         INT32_C(           0),  INT32_C(   995039644), -INT32_C(  1669624375),  INT32_C(           0),  INT32_C(           0),  INT32_C(  1056882053),  INT32_C(           2),  INT32_C(  1612865681) } },
    { { -INT32_C(  1034280695), -INT32_C(  1039103454),  INT32_C(  1938999729),  INT32_C(  1627515063),  INT32_C(  1728338305), -INT32_C(  1096466243), -INT32_C(  2084741769), -INT32_C(  1344514394),
        -INT32_C(  1703856265),  INT32_C(  1918665409),  INT32_C(    48623179),  INT32_C(  1482942166), -INT32_C(    37787841),  INT32_C(   532374696),  INT32_C(  1755478209),  INT32_C(  1175944911) },
      UINT16_C( 9625),
      {  INT32_C(  1994426805),  INT32_C(  1458060555),  INT32_C(    39374123), -INT32_C(   212157261), -INT32_C(   873457373),  INT32_C(  1055566717), -INT32_C(   207188956), -INT32_C(  1069957621),
         INT32_C(  1379342919), -INT32_C(  2102911145), -INT32_C(  1601961747), -INT32_C(   527180100),  INT32_C(  1957397495),  INT32_C(  1404278319),  INT32_C(   759585058),  INT32_C(  1592688407) },
      {  INT32_C(           1), -INT32_C(  1039103454),  INT32_C(  1938999729),  INT32_C(           0),  INT32_C(           0), -INT32_C(  1096466243), -INT32_C(  2084741769),  INT32_C(           0),
         INT32_C(           1),  INT32_C(  1918665409),  INT32_C(           0),  INT32_C(  1482942166), -INT32_C(    37787841),  INT32_C(           1),  INT32_C(  1755478209),  INT32_C(  1175944911) } },
    { {  INT32_C(  1480913072), -INT32_C(   145149581),  INT32_C(  1708529106), -INT32_C(  1578512907), -INT32_C(   180938686), -INT32_C(  1320265365),  INT32_C(  1966106247),  INT32_C(  1973078724),
         INT32_C(   768466618), -INT32_C(   500881904),  INT32_C(   826800956),  INT32_C(   181547208), -INT32_C(  1275131576), -INT32_C(   362525085),  INT32_C(  2019530164),  INT32_C(   435026271) },
      UINT16_C(55943),
      { -INT32_C(   414729257),  INT32_C(   499739873),  INT32_C(   793710951), -INT32_C(  1975901887), -INT32_C(  1908590293),  INT32_C(   997761671), -INT32_C(  1766533321), -INT32_C(  1481662000),
         INT32_C(  1049622108), -INT32_C(   916760478), -INT32_C(  1409701271), -INT32_C(   147508276), -INT32_C(   192581012),  INT32_C(  1261436180), -INT32_C(  1528699948), -INT32_C(   515141243) },
      {  INT32_C(           0),  INT32_C(           3),  INT32_C(           2), -INT32_C(  1578512907), -INT32_C(   180938686), -INT32_C(  1320265365),  INT32_C(  1966106247),  INT32_C(           0),
         INT32_C(   768466618),  INT32_C(           0),  INT32_C(   826800956),  INT32_C(           0),  INT32_C(           0), -INT32_C(   362525085),  INT32_C(           0),  INT32_C(           0) } },
    { {  INT32_C(  2066999839), -INT32_C(  1406821197),  INT32_C(  2095051079),  INT32_C(  1844399336),  INT32_C(  1869218624),  INT32_C(   810761807),  INT32_C(   784455906), -INT32_C(   653768263),
        -INT32_C(   430687437),  INT32_C(   529758680),  INT32_C(  1402761835), -INT32_C(    20870210), -INT32_C(   579982450),  INT32_C(  1276035434),  INT32_C(  1383780249),  INT32_C(  1261142808) },
      UINT16_C(17482),
      { -INT32_C(  1775075394),  INT32_C(  1689699833), -INT32_C(   155758025),  INT32_C(  1811183837),  INT32_C(   239690404), -INT32_C(  1134930141),  INT32_C(  1058002214),  INT32_C(   378157656),
        -INT32_C(  1280459590), -INT32_C(  1189649535), -INT32_C(  1833972043), -INT32_C(   335699129),  INT32_C(   704202246), -INT32_C(   991538275), -INT32_C(  2147224280), -INT32_C(   375943889) },
      {  INT32_C(  2066999839),  INT32_C(           1),  INT32_C(  2095051079),  INT32_C(           1),  INT32_C(  1869218624),  INT32_C(   810761807),  INT32_C(           2), -INT32_C(   653768263),
        -INT32_C(   430687437),  INT32_C(   529758680),  INT32_C(           0), -INT32_C(    20870210), -INT32_C(   579982450),  INT32_C(  1276035434),  INT32_C(           0),  INT32_C(  1261142808) } },
    { { -INT32_C(  1280848996),  INT32_C(   864181380), -INT32_C(   338179602), -INT32_C(  1389175372), -INT32_C(   335491322), -INT32_C(  1763628653),  INT32_C(  1076105641), -INT32_C(  1752928518),
        -INT32_C(  1102435527),  INT32_C(  1978780807),  INT32_C(  1231145109), -INT32_C(  1393126491), -INT32_C(   157747358), -INT32_C(   913540576), -INT32_C(  2062897013),  INT32_C(  1478266398) },
      UINT16_C( 6332),
      {  INT32_C(  1091987386), -INT32_C(   910751949),  INT32_C(  1964120272),  INT32_C(   220268971),  INT32_C(   537115136), -INT32_C(  1075212236),  INT32_C(  1598354240),  INT32_C(  1018651010),
        -INT32_C(    75641400), -INT32_C(  1530645292), -INT32_C(   149235892), -INT32_C(   536527904),  INT32_C(   687868149), -INT32_C(   639047272),  INT32_C(  1597517277),  INT32_C(  1453059982) },
      { -INT32_C(  1280848996),  INT32_C(   864181380),  INT32_C(           1),  INT32_C(           4),  INT32_C(           2),  INT32_C(           0),  INT32_C(  1076105641),  INT32_C(           2),
        -INT32_C(  1102435527),  INT32_C(  1978780807),  INT32_C(  1231145109),  INT32_C(           0),  INT32_C(           2), -INT32_C(   913540576), -INT32_C(  2062897013),  INT32_C(  1478266398) } },
    { {  INT32_C(   374181969),  INT32_C(  1340971317), -INT32_C(  1769288303), -INT32_C(  1382121299), -INT32_C(  1835649111),  INT32_C(  1220506384),  INT32_C(  1832340946), -INT32_C(   192482397),
        -INT32_C(  1207250045), -INT32_C(    49809556),  INT32_C(  1905496772), -INT32_C(  1155649006),  INT32_C(  2035135849), -INT32_C(    71234520), -INT32_C(    60229543),  INT32_C(  1861349099) },
      UINT16_C( 9720),
      {  INT32_C(   774372289), -INT32_C(  1221906701), -INT32_C(   769015872),  INT32_C(  1519273969),  INT32_C(   634641404),  INT32_C(  1092654312),  INT32_C(  2000586892),  INT32_C(   954543991),
         INT32_C(   493227050), -INT32_C(    69889477),  INT32_C(  1120861777),  INT32_C(  1117543493),  INT32_C(   526872375), -INT32_C(  1889433853), -INT32_C(  2046386417), -INT32_C(   121639986) },
      {  INT32_C(   374181969),  INT32_C(  1340971317), -INT32_C(  1769288303),  INT32_C(           1),  INT32_C(           2),  INT32_C(           1),  INT32_C(           1),  INT32_C(           2),
         INT32_C(           3), -INT32_C(    49809556),  INT32_C(           1), -INT32_C(  1155649006),  INT32_C(  2035135849),  INT32_C(           0), -INT32_C(    60229543),  INT32_C(  1861349099) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m512i src = simde_mm512_loadu_epi32(test_vec[i].src);
    simde__m512i a = simde_mm512_loadu_epi32(test_vec[i].a);
    simde__m512i r = simde_mm512_mask_lzcnt_epi32(src, test_vec[i].k, a);
    simde_test_x86_assert_equal_i32x16(r, simde_mm512_loadu_epi32(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m512i src = simde_test_x86_random_i32x16();
    simde__m512i a = simde_test_x86_random_i32x16();
    simde__mmask16 k = simde_test_x86_random_mmask16();
    simde__m512i r = simde_mm512_mask_lzcnt_epi32(src, k, a);

    simde_test_x86_write_i32x16(2, src, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_mmask16(2, k, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i32x16(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i32x16(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm512_maskz_lzcnt_epi32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  const struct {
    const simde__mmask16 k;
    const int32_t a[16];
    const int32_t r[16];
  } test_vec[] = {
    { UINT16_C(32180),
      { -INT32_C(   340315370), -INT32_C(    51836882), -INT32_C(   430428598), -INT32_C(   682258320),  INT32_C(   274618543), -INT32_C(   307269913), -INT32_C(  1277592076), -INT32_C(  1931882122),
         INT32_C(   846696452), -INT32_C(   483434343), -INT32_C(     3504242), -INT32_C(   942268649),  INT32_C(  1607939448), -INT32_C(  1756526685),  INT32_C(  2051745284), -INT32_C(    83483401) },
      {  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           3),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),
         INT32_C(           2),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           1),  INT32_C(           0),  INT32_C(           1),  INT32_C(           0) } },
    { UINT16_C(43471),
      {  INT32_C(  1558007085), -INT32_C(    68916175),  INT32_C(  1092287339), -INT32_C(  1703505214),  INT32_C(  1059133938), -INT32_C(    60480079), -INT32_C(  1507828576), -INT32_C(  2077961129),
         INT32_C(  1407254818), -INT32_C(   665926291), -INT32_C(  2095421248), -INT32_C(   316829445),  INT32_C(  1529626282),  INT32_C(    56070499),  INT32_C(  1152022509),  INT32_C(  1841876555) },
      {  INT32_C(           1),  INT32_C(           0),  INT32_C(           1),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),
         INT32_C(           1),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           6),  INT32_C(           0),  INT32_C(           1) } },
    { UINT16_C(11618),
      {  INT32_C(   242105792),  INT32_C(   796339989), -INT32_C(   809471310), -INT32_C(  1962055073),  INT32_C(   471625925),  INT32_C(   512952692),  INT32_C(   367844941),  INT32_C(   213891916),
         INT32_C(   236662264),  INT32_C(   238916188),  INT32_C(  1675492612),  INT32_C(   753855079), -INT32_C(   817362341),  INT32_C(  1626200851),  INT32_C(   108386746), -INT32_C(  1928186732) },
      {  INT32_C(           0),  INT32_C(           2),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           3),  INT32_C(           3),  INT32_C(           0),
         INT32_C(           4),  INT32_C(           0),  INT32_C(           1),  INT32_C(           2),  INT32_C(           0),  INT32_C(           1),  INT32_C(           0),  INT32_C(           0) } },
    { UINT16_C(25770),
      { -INT32_C(   658522469), -INT32_C(  1428765747),  INT32_C(   345324838), -INT32_C(  1306595222), -INT32_C(  1399967297),  INT32_C(   126175377),  INT32_C(  1614485838),  INT32_C(  1099865510),
         INT32_C(   689589596),  INT32_C(   936636433), -INT32_C(  1756600275),  INT32_C(   390752856),  INT32_C(   767809692),  INT32_C(  1848920096),  INT32_C(   147746914),  INT32_C(  1766480909) },
      {  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           5),  INT32_C(           0),  INT32_C(           1),
         INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           1),  INT32_C(           4),  INT32_C(           0) } },
    { UINT16_C(  641),
      {  INT32_C(  1716829074),  INT32_C(  1053721074),  INT32_C(  1672029977),  INT32_C(    37438782), -INT32_C(  1488299150), -INT32_C(  1760056119), -INT32_C(      777035),  INT32_C(   543399566),
         INT32_C(  1267119961),  INT32_C(  1368020280), -INT32_C(  1162595460), -INT32_C(   356716680),  INT32_C(   328271690),  INT32_C(  1756080307),  INT32_C(  1533517773), -INT32_C(  1770272195) },
      {  INT32_C(           1),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           2),
         INT32_C(           0),  INT32_C(           1),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0) } },
    { UINT16_C(44892),
      {  INT32_C(  1800911585), -INT32_C(  1063333109),  INT32_C(  1252988557), -INT32_C(  1840121343), -INT32_C(  1204091891), -INT32_C(   732493715), -INT32_C(   559967133),  INT32_C(   216014890),
        -INT32_C(   428394534), -INT32_C(  1733945846),  INT32_C(   769807660),  INT32_C(  1572877135), -INT32_C(  1542063305),  INT32_C(  1719233795),  INT32_C(   742660097),  INT32_C(   322446648) },
      {  INT32_C(           0),  INT32_C(           0),  INT32_C(           1),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),
         INT32_C(           0),  INT32_C(           0),  INT32_C(           2),  INT32_C(           1),  INT32_C(           0),  INT32_C(           1),  INT32_C(           0),  INT32_C(           3) } },
    { UINT16_C(14925),
      { -INT32_C(  1614452743), -INT32_C(   504040705), -INT32_C(   552319969), -INT32_C(  1227207775),  INT32_C(  1763958256), -INT32_C(  2004802237), -INT32_C(  1985103535), -INT32_C(   986183220),
         INT32_C(  1868889712),  INT32_C(   256924144),  INT32_C(  1055876253), -INT32_C(  1594570320), -INT32_C(   368502617), -INT32_C(  1905096131),  INT32_C(   269950787), -INT32_C(  1714073815) },
      {  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),
         INT32_C(           0),  INT32_C(           4),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0) } },
    { UINT16_C(47998),
      {  INT32_C(  1502821641),  INT32_C(  1019097165),  INT32_C(  1644523118),  INT32_C(   393915406),  INT32_C(   161593239),  INT32_C(  1546249285), -INT32_C(   894676236), -INT32_C(   201000469),
        -INT32_C(  2075224265),  INT32_C(   901778631), -INT32_C(  2003319430),  INT32_C(   161419890),  INT32_C(   252854473),  INT32_C(   426457892),  INT32_C(  2044925837),  INT32_C(  1215162129) },
      {  INT32_C(           0),  INT32_C(           2),  INT32_C(           1),  INT32_C(           3),  INT32_C(           4),  INT32_C(           1),  INT32_C(           0),  INT32_C(           0),
         INT32_C(           0),  INT32_C(           2),  INT32_C(           0),  INT32_C(           4),  INT32_C(           4),  INT32_C(           3),  INT32_C(           0),  INT32_C(           1) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m512i a = simde_mm512_loadu_epi32(test_vec[i].a);
    simde__m512i r = simde_mm512_maskz_lzcnt_epi32(test_vec[i].k, a);
    simde_test_x86_assert_equal_i32x16(r, simde_mm512_loadu_epi32(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m512i a = simde_test_x86_random_i32x16();
    simde__mmask16 k = simde_test_x86_random_mmask16();
    simde__m512i r = simde_mm512_maskz_lzcnt_epi32( k, a);

    simde_test_x86_write_mmask16(2, k, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i32x16(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i32x16(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm_lzcnt_epi64(SIMDE_MUNIT_TEST_ARGS) {
#if 0
  const struct {
    const int64_t a[2];
    const int64_t r[2];
  } test_vec[] = {
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128i a = simde_mm_loadu_epi64(test_vec[i].a);
    simde__m128i r = simde_mm_lzcnt_epi64(a);
    simde_test_x86_assert_equal_i64x2(r, simde_mm_loadu_epi64(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m128i a = simde_test_x86_random_i64x2();
    simde__m128i r = simde_mm_lzcnt_epi64(a);

    simde_test_x86_write_i64x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i64x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm_mask_lzcnt_epi64 (SIMDE_MUNIT_TEST_ARGS) {
#if 0
  const struct {
    const int64_t src[2];
    const simde__mmask8 k;
    const int64_t a[2];
    const int64_t r[2];
  } test_vec[] = {
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128i src = simde_mm_loadu_epi64(test_vec[i].src);
    simde__m128i a = simde_mm_loadu_epi64(test_vec[i].a);
    simde__m128i r = simde_mm_mask_lzcnt_epi64(src, test_vec[i].k, a);
    simde_test_x86_assert_equal_i64x2(r, simde_mm_loadu_epi64(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m128i src = simde_test_x86_random_i64x2();
    simde__mmask8 k = simde_test_x86_random_mmask8();
    simde__m128i a = simde_test_x86_random_i64x2();
    simde__m128i r = simde_mm_mask_lzcnt_epi64(src, k, a);

    simde_test_x86_write_i64x2(2, src, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_mmask8(2, k, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i64x2(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i64x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm_maskz_lzcnt_epi64 (SIMDE_MUNIT_TEST_ARGS) {
#if 0
  const struct {
    const simde__mmask8 k;
    const int64_t a[2];
    const int64_t r[2];
  } test_vec[] = {
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128i a = simde_mm_loadu_epi64(test_vec[i].a);
    simde__m128i r = simde_mm_maskz_lzcnt_epi64(test_vec[i].k, a);
    simde_test_x86_assert_equal_i64x2(r, simde_mm_loadu_epi64(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__mmask8 k = simde_test_x86_random_mmask8();
    simde__m128i a = simde_test_x86_random_i64x2();
    simde__m128i r = simde_mm_maskz_lzcnt_epi64( k, a);

    simde_test_x86_write_mmask8(2, k, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i64x2(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i64x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm256_lzcnt_epi64(SIMDE_MUNIT_TEST_ARGS) {
#if 0 
  const struct {
    const int64_t a[4];
    const int64_t r[4];
  } test_vec[] = {
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m256i a = simde_mm256_loadu_epi64(test_vec[i].a);
    simde__m256i r = simde_mm256_lzcnt_epi64(a);
    simde_test_x86_assert_equal_i64x4(r, simde_mm256_loadu_epi64(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m256i a = simde_test_x86_random_i64x4();
    simde__m256i r = simde_mm256_lzcnt_epi64(a);

    simde_test_x86_write_i64x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i64x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm256_mask_lzcnt_epi64 (SIMDE_MUNIT_TEST_ARGS) {
#if 0
  const struct {
    const int64_t src[4];
    const simde__mmask8 k;
    const int64_t a[4];
    const int64_t r[4];
  } test_vec[] = {
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m256i src = simde_mm256_loadu_epi64(test_vec[i].src);
    simde__m256i a = simde_mm256_loadu_epi64(test_vec[i].a);
    simde__m256i r = simde_mm256_mask_lzcnt_epi64(src, test_vec[i].k, a);
    simde_test_x86_assert_equal_i64x4(r, simde_mm256_loadu_epi64(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m256i src = simde_test_x86_random_i64x4();
    simde__m256i a = simde_test_x86_random_i64x4();
    simde__mmask8 k = simde_test_x86_random_mmask8();
    simde__m256i r = simde_mm256_mask_lzcnt_epi64(src, k, a);

    simde_test_x86_write_i64x4(2, src, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_mmask8(2, k, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i64x4(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i64x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm256_maskz_lzcnt_epi64 (SIMDE_MUNIT_TEST_ARGS) {
#if 0
  const struct {
    const simde__mmask8 k;
    const int64_t a[4];
    const int64_t r[4];
  } test_vec[] = {
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m256i a = simde_mm256_loadu_epi64(test_vec[i].a);
    simde__m256i r = simde_mm256_maskz_lzcnt_epi64(test_vec[i].k, a);
    simde_test_x86_assert_equal_i64x4(r, simde_mm256_loadu_epi64(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m256i a = simde_test_x86_random_i64x4();
    simde__mmask8 k = simde_test_x86_random_mmask8();
    simde__m256i r = simde_mm256_maskz_lzcnt_epi64( k, a);

    simde_test_x86_write_mmask8(2, k, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i64x4(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i64x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm512_lzcnt_epi64(SIMDE_MUNIT_TEST_ARGS) {
#if 0
  const struct {
    const int64_t a[16];
    const int64_t r[16];
  } test_vec[] = {
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m512i a = simde_mm512_loadu_epi64(test_vec[i].a);
    simde__m512i r = simde_mm512_lzcnt_epi64(a);
    simde_test_x86_assert_equal_i64x8(r, simde_mm512_loadu_epi64(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m512i a = simde_test_x86_random_i64x8();
    simde__m512i r = simde_mm512_lzcnt_epi64(a);

    simde_test_x86_write_i64x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i64x8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm512_mask_lzcnt_epi64 (SIMDE_MUNIT_TEST_ARGS) {
#if 0
  const struct {
    const int64_t src[16];
    const simde__mmask8 k;
    const int64_t a[16];
    const int64_t r[16];
  } test_vec[] = {
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m512i src = simde_mm512_loadu_epi64(test_vec[i].src);
    simde__m512i a = simde_mm512_loadu_epi64(test_vec[i].a);
    simde__m512i r = simde_mm512_mask_lzcnt_epi64(src, test_vec[i].k, a);
    simde_test_x86_assert_equal_i64x8(r, simde_mm512_loadu_epi64(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m512i src = simde_test_x86_random_i64x8();
    simde__m512i a = simde_test_x86_random_i64x8();
    simde__mmask8 k = simde_test_x86_random_mmask8();
    simde__m512i r = simde_mm512_mask_lzcnt_epi64(src, k, a);

    simde_test_x86_write_i64x8(2, src, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_mmask8(2, k, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i64x8(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i64x8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm512_maskz_lzcnt_epi64 (SIMDE_MUNIT_TEST_ARGS) {
#if 0
  const struct {
    const simde__mmask8 k;
    const int64_t a[16];
    const int64_t r[16];
  } test_vec[] = {
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m512i a = simde_mm512_loadu_epi64(test_vec[i].a);
    simde__m512i r = simde_mm512_maskz_lzcnt_epi64(test_vec[i].k, a);
    simde_test_x86_assert_equal_i64x8(r, simde_mm512_loadu_epi64(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m512i a = simde_test_x86_random_i64x8();
    simde__mmask8 k = simde_test_x86_random_mmask8();
    simde__m512i r = simde_mm512_maskz_lzcnt_epi64(k, a);

    simde_test_x86_write_mmask8(2, k, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i64x8(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i64x8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}


SIMDE_TEST_FUNC_LIST_BEGIN
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_lzcnt_epi32)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_mask_lzcnt_epi32)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_maskz_lzcnt_epi32)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm256_lzcnt_epi32)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm256_mask_lzcnt_epi32)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm256_maskz_lzcnt_epi32)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_lzcnt_epi32)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_mask_lzcnt_epi32)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_maskz_lzcnt_epi32)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_lzcnt_epi64)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_mask_lzcnt_epi64)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_maskz_lzcnt_epi64)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm256_lzcnt_epi64)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm256_mask_lzcnt_epi64)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm256_maskz_lzcnt_epi64)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_lzcnt_epi64)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_mask_lzcnt_epi64)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_maskz_lzcnt_epi64)
SIMDE_TEST_FUNC_LIST_END

#include <test/x86/avx512/test-avx512-footer.h>
