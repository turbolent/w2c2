
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_float_misc.0.h"

void test() {
    m12_floatX5FmiscX2E0Instance instance;
    m12_floatX5FmiscX2E0Instantiate(&instance, resolveTestImports);
    printStart("float_misc.0.wasm");
    assertEqualU32(
        i32_reinterpret_f32(m12_floatX5FmiscX2E0Export7_f32X2Eadd(&instance, 1.1234568357467651, 1.2345000022229158e-10)),
        1066388847u,
        "f32.add(1.1234568357467651, 1.2345000022229158e-10)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m12_floatX5FmiscX2E0Export7_f64X2Eadd(&instance, 1.123456789, 1.2345e-10)),
        4607738418749510135ull,
        "f64.add(1.123456789, 1.2345e-10)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m12_floatX5FmiscX2E0Export7_f32X2Eadd(&instance, 1.0, 5.960464477539063e-08)),
        1065353216u,
        "f32.add(1.0, 5.960464477539063e-08)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m12_floatX5FmiscX2E0Export7_f32X2Eadd(&instance, 1.0, 5.960465188081798e-08)),
        1065353217u,
        "f32.add(1.0, 5.960465188081798e-08)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m12_floatX5FmiscX2E0Export7_f64X2Eadd(&instance, 1.0, 1.1102230246251565e-16)),
        4607182418800017408ull,
        "f64.add(1.0, 1.1102230246251565e-16)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m12_floatX5FmiscX2E0Export7_f64X2Eadd(&instance, 1.0, 1.1102230246251568e-16)),
        4607182418800017409ull,
        "f64.add(1.0, 1.1102230246251568e-16)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m12_floatX5FmiscX2E0Export7_f32X2Eadd(&instance, 1.401298464324817e-45, 1.1754942106924411e-38)),
        8388608u,
        "f32.add(1.401298464324817e-45, 1.1754942106924411e-38)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m12_floatX5FmiscX2E0Export7_f64X2Eadd(&instance, 5e-324, 2.225073858507201e-308)),
        4503599627370496ull,
        "f64.add(5e-324, 2.225073858507201e-308)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m12_floatX5FmiscX2E0Export7_f32X2Eadd(&instance, 2147483648.0, 1024.25)),
        1325400068u,
        "f32.add(2147483648.0, 1024.25)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m12_floatX5FmiscX2E0Export7_f64X2Eadd(&instance, 9.223372036854776e+18, 1024.25)),
        4890909195324358657ull,
        "f64.add(9.223372036854776e+18, 1024.25)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m12_floatX5FmiscX2E0Export7_f64X2Eadd(&instance, -3.645561009778199e-304, 2.92e-320)),
        9290926031265333247ull,
        "f64.add(-3.645561009778199e-304, 2.92e-320)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m12_floatX5FmiscX2E0Export7_f64X2Eadd(&instance, 9007199254740992.0, 1.00001)),
        4845873199050653697ull,
        "f64.add(9007199254740992.0, 1.00001)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m12_floatX5FmiscX2E0Export7_f64X2Eadd(&instance, 9007199254740994.0, 0.9999847412109375)),
        4845873199050653697ull,
        "f64.add(9007199254740994.0, 0.9999847412109375)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m12_floatX5FmiscX2E0Export7_f32X2Eadd(&instance, 8388608.0, 0.5)),
        1258291200u,
        "f32.add(8388608.0, 0.5)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m12_floatX5FmiscX2E0Export7_f32X2Eadd(&instance, 8388609.0, 0.5)),
        1258291202u,
        "f32.add(8388609.0, 0.5)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m12_floatX5FmiscX2E0Export7_f64X2Eadd(&instance, 4503599627370496.0, 0.5)),
        4841369599423283200ull,
        "f64.add(4503599627370496.0, 0.5)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m12_floatX5FmiscX2E0Export7_f64X2Eadd(&instance, 4503599627370497.0, 0.5)),
        4841369599423283202ull,
        "f64.add(4503599627370497.0, 0.5)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m12_floatX5FmiscX2E0Export7_f32X2Eadd(&instance, -6.207600156575025e+30, 2.3097990034335698e-30)),
        4070355885u,
        "f32.add(-6.207600156575025e+30, 2.3097990034335698e-30)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m12_floatX5FmiscX2E0Export7_f32X2Eadd(&instance, 2.0986580749500023e+20, -5270152505458688.0)),
        1630930534u,
        "f32.add(2.0986580749500023e+20, -5270152505458688.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m12_floatX5FmiscX2E0Export7_f32X2Eadd(&instance, 1.9634920494274e-25, 4.622006701228597e-38)),
        376639884u,
        "f32.add(1.9634920494274e-25, 4.622006701228597e-38)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m12_floatX5FmiscX2E0Export7_f32X2Eadd(&instance, 640904986624.0, -6.444954909933568e+16)),
        3680827377u,
        "f32.add(640904986624.0, -6.444954909933568e+16)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m12_floatX5FmiscX2E0Export7_f32X2Eadd(&instance, 6.019659849698655e-05, 1.2037279221606141e+32)),
        1958603311u,
        "f32.add(6.019659849698655e-05, 1.2037279221606141e+32)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m12_floatX5FmiscX2E0Export7_f64X2Eadd(&instance, 9.218993827002741e-125, -1.2830782438780485e+75)),
        14953834855654151696ull,
        "f64.add(9.218993827002741e-125, -1.2830782438780485e+75)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m12_floatX5FmiscX2E0Export7_f64X2Eadd(&instance, -9.650340787014896e+22, 4.670208988478548e-56)),
        14174076479053295281ull,
        "f64.add(-9.650340787014896e+22, 4.670208988478548e-56)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m12_floatX5FmiscX2E0Export7_f64X2Eadd(&instance, 2.8559147675434106e-45, -0.00026124280570653086)),
        13776826739676942972ull,
        "f64.add(2.8559147675434106e-45, -0.00026124280570653086)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m12_floatX5FmiscX2E0Export7_f64X2Eadd(&instance, 4.179099281652967e+149, 7.93355647415127e+19)),
        6845567588107709194ull,
        "f64.add(4.179099281652967e+149, 7.93355647415127e+19)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m12_floatX5FmiscX2E0Export7_f64X2Eadd(&instance, 8.265442868747023e+96, 4.360332783900625e+118)),
        6381964069811498464ull,
        "f64.add(8.265442868747023e+96, 4.360332783900625e+118)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m12_floatX5FmiscX2E0Export7_f32X2Eadd(&instance, 5.238404127822499e+21, -1570182.5)),
        1670249659u,
        "f32.add(5.238404127822499e+21, -1570182.5)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m12_floatX5FmiscX2E0Export7_f32X2Eadd(&instance, 4.25893790178232e-14, -5.70923525670006e-24)),
        692047414u,
        "f32.add(4.25893790178232e-14, -5.70923525670006e-24)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m12_floatX5FmiscX2E0Export7_f32X2Eadd(&instance, -2.7251025871630197e-13, 8.371155873353713e+37)),
        2122049802u,
        "f32.add(-2.7251025871630197e-13, 8.371155873353713e+37)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m12_floatX5FmiscX2E0Export7_f32X2Eadd(&instance, -8.845359747390244e-14, -1.5165625673454357e-32)),
        2848402951u,
        "f32.add(-8.845359747390244e-14, -1.5165625673454357e-32)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m12_floatX5FmiscX2E0Export7_f32X2Eadd(&instance, 0.0010521034710109234, -7.582134723423548e-33)),
        982116028u,
        "f32.add(0.0010521034710109234, -7.582134723423548e-33)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m12_floatX5FmiscX2E0Export7_f64X2Eadd(&instance, 1.5111352281889246e+54, -2.760218100603169e-159)),
        5417704807092288842ull,
        "f64.add(1.5111352281889246e+54, -2.760218100603169e-159)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m12_floatX5FmiscX2E0Export7_f64X2Eadd(&instance, 6.238671976036028e+46, -8.592185488839212e-19)),
        5306888566943064716ull,
        "f64.add(6.238671976036028e+46, -8.592185488839212e-19)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m12_floatX5FmiscX2E0Export7_f64X2Eadd(&instance, 4.195022848436354e-122, -2.9225342022551453e-295)),
        2791030278657170439ull,
        "f64.add(4.195022848436354e-122, -2.9225342022551453e-295)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m12_floatX5FmiscX2E0Export7_f64X2Eadd(&instance, -2.1522054671482452e+44, -1.1122204120471372e+42)),
        14493541008051035082ull,
        "f64.add(-2.1522054671482452e+44, -1.1122204120471372e+42)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m12_floatX5FmiscX2E0Export7_f64X2Eadd(&instance, -13.6911535055856, 2.0661178989244198e+87)),
        5913400236268010570ull,
        "f64.add(-13.6911535055856, 2.0661178989244198e+87)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m12_floatX5FmiscX2E0Export7_f32X2Eadd(&instance, -6.456021030610507e-36, 2.0219949033260104e-13)),
        711174153u,
        "f32.add(-6.456021030610507e-36, 2.0219949033260104e-13)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m12_floatX5FmiscX2E0Export7_f32X2Eadd(&instance, -2.6823168809642084e-05, 1.119601567012296e-08)),
        3084970566u,
        "f32.add(-2.6823168809642084e-05, 1.119601567012296e-08)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m12_floatX5FmiscX2E0Export7_f32X2Eadd(&instance, -128526172160.0, 2.73563047337179e-33)),
        3522127374u,
        "f32.add(-128526172160.0, 2.73563047337179e-33)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m12_floatX5FmiscX2E0Export7_f32X2Eadd(&instance, 4.158973127324512e-36, -1573528704.0)),
        3468399689u,
        "f32.add(4.158973127324512e-36, -1573528704.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m12_floatX5FmiscX2E0Export7_f32X2Eadd(&instance, -9.338768644095452e-37, 7.8647514498630135e+28)),
        1870536627u,
        "f32.add(-9.338768644095452e-37, 7.8647514498630135e+28)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m12_floatX5FmiscX2E0Export7_f64X2Eadd(&instance, 2.1986596650683218e-234, -2.3544759484546134e+302)),
        18353849863141451174ull,
        "f64.add(2.1986596650683218e-234, -2.3544759484546134e+302)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m12_floatX5FmiscX2E0Export7_f64X2Eadd(&instance, -3.141756195935957e+155, -3.011409851461166e+148)),
        16156503867159194550ull,
        "f64.add(-3.141756195935957e+155, -3.011409851461166e+148)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m12_floatX5FmiscX2E0Export7_f64X2Eadd(&instance, -1.3722858367681836e-291, 1.1571842749688977e-85)),
        3336259491488022866ull,
        "f64.add(-1.3722858367681836e-291, 1.1571842749688977e-85)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m12_floatX5FmiscX2E0Export7_f64X2Eadd(&instance, -9.828583756551075e-154, 1.6862581574752944e-259)),
        11541137186853127278ull,
        "f64.add(-9.828583756551075e-154, 1.6862581574752944e-259)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m12_floatX5FmiscX2E0Export7_f64X2Eadd(&instance, -6.725842035221635e+290, 8.374007930974482e+240)),
        18181384676953296798ull,
        "f64.add(-6.725842035221635e+290, 8.374007930974482e+240)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m12_floatX5FmiscX2E0Export7_f64X2Eadd(&instance, -2.1089660532788995e+242, 5.814832334211963e+248)),
        8328504328029232689ull,
        "f64.add(-2.1089660532788995e+242, 5.814832334211963e+248)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m12_floatX5FmiscX2E0Export7_f64X2Eadd(&instance, 1.0231579266682148e+236, 4.502043007974949e+224)),
        8138029755241745167ull,
        "f64.add(1.0231579266682148e+236, 4.502043007974949e+224)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m12_floatX5FmiscX2E0Export7_f64X2Eadd(&instance, -1.3052997857095656e+188, 1.5489943422018657e+203)),
        7647005019700459387ull,
        "f64.add(-1.3052997857095656e+188, 1.5489943422018657e+203)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m12_floatX5FmiscX2E0Export7_f64X2Eadd(&instance, 4.7629997434721684e+139, 4.555864510582597e+155)),
        6935821972358342665ull,
        "f64.add(4.7629997434721684e+139, 4.555864510582597e+155)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m12_floatX5FmiscX2E0Export7_f64X2Eadd(&instance, 3.958952516558414e-300, 2.3092460710062946e-290)),
        273820416704834831ull,
        "f64.add(3.958952516558414e-300, 2.3092460710062946e-290)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m12_floatX5FmiscX2E0Export7_f64X2Eadd(&instance, -4.3780558475415996e+226, -4.9680759347383435e+286)),
        18119355194379769652ull,
        "f64.add(-4.3780558475415996e+226, -4.9680759347383435e+286)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m12_floatX5FmiscX2E0Export7_f64X2Eadd(&instance, 2.117431116854608e+58, -2.6385928474612128e+82)),
        15063363222154738502ull,
        "f64.add(2.117431116854608e+58, -2.6385928474612128e+82)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m12_floatX5FmiscX2E0Export7_f64X2Eadd(&instance, -9.508489561700635e+90, 7.858068235728165e-128)),
        15191393426281101490ull,
        "f64.add(-9.508489561700635e+90, 7.858068235728165e-128)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m12_floatX5FmiscX2E0Export7_f64X2Eadd(&instance, -5.079144928553737e-96, -3.540217207424998e+140)),
        15933096090325362723ull,
        "f64.add(-5.079144928553737e-96, -3.540217207424998e+140)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m12_floatX5FmiscX2E0Export7_f64X2Eadd(&instance, -4.165382103988111e-60, 1.0865942283516648e-298)),
        12941874353187635000ull,
        "f64.add(-4.165382103988111e-60, 1.0865942283516648e-298)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m12_floatX5FmiscX2E0Export7_f32X2Eadd(&instance, 9.721564916252783e+34, 3.0559086703943176e+38)),
        2137389410u,
        "f32.add(9.721564916252783e+34, 3.0559086703943176e+38)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m12_floatX5FmiscX2E0Export7_f32X2Eadd(&instance, 2.7046562782855097e+38, -2.3023684683832103e+32)),
        2135652798u,
        "f32.add(2.7046562782855097e+38, -2.3023684683832103e+32)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m12_floatX5FmiscX2E0Export7_f32X2Eadd(&instance, 3.572092819342499e+35, -2.364940520759259e+38)),
        4281443917u,
        "f32.add(3.572092819342499e+35, -2.364940520759259e+38)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m12_floatX5FmiscX2E0Export7_f32X2Eadd(&instance, -1.4842340927922734e+36, -3.2899139288350082e+38)),
        4286095178u,
        "f32.add(-1.4842340927922734e+36, -3.2899139288350082e+38)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m12_floatX5FmiscX2E0Export7_f32X2Eadd(&instance, -2.1988559814787968e+38, -8.156092864302113e+37)),
        4284663933u,
        "f32.add(-2.1988559814787968e+38, -8.156092864302113e+37)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m12_floatX5FmiscX2E0Export7_f64X2Eadd(&instance, 9.039020493954763e+307, 2.2943337422040356e+295)),
        9214390167692529673ull,
        "f64.add(9.039020493954763e+307, 2.2943337422040356e+295)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m12_floatX5FmiscX2E0Export7_f64X2Eadd(&instance, 1.6591605973624605e+308, 1.257734933144416e+298)),
        9218174330906813073ull,
        "f64.add(1.6591605973624605e+308, 1.257734933144416e+298)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m12_floatX5FmiscX2E0Export7_f64X2Eadd(&instance, -1.363512925613943e+308, 6.050703060387358e+304)),
        18440062016830479601ull,
        "f64.add(-1.363512925613943e+308, 6.050703060387358e+304)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m12_floatX5FmiscX2E0Export7_f64X2Eadd(&instance, -3.4377613258227424e+301, 1.6994715275879349e+308)),
        9218376303911020838ull,
        "f64.add(-3.4377613258227424e+301, 1.6994715275879349e+308)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m12_floatX5FmiscX2E0Export7_f64X2Eadd(&instance, 9.227342700864557e+307, -3.926941645101868e+298)),
        9214484525042704878ull,
        "f64.add(9.227342700864557e+307, -3.926941645101868e+298)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m12_floatX5FmiscX2E0Export7_f32X2Eadd(&instance, 8.313455373330556e-39, 8.73008943274361e-43)),
        5933303u,
        "f32.add(8.313455373330556e-39, 8.73008943274361e-43)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m12_floatX5FmiscX2E0Export7_f32X2Eadd(&instance, 5.184804318001823e-44, -2.802596928649634e-45)),
        35u,
        "f32.add(5.184804318001823e-44, -2.802596928649634e-45)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m12_floatX5FmiscX2E0Export7_f32X2Eadd(&instance, -1.1210387714598537e-44, 5.18628408918015e-39)),
        3701048u,
        "f32.add(-1.1210387714598537e-44, 5.18628408918015e-39)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m12_floatX5FmiscX2E0Export7_f32X2Eadd(&instance, -2.802596928649634e-44, 2.3675282834709394e-37)),
        44113960u,
        "f32.add(-2.802596928649634e-44, 2.3675282834709394e-37)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m12_floatX5FmiscX2E0Export7_f32X2Eadd(&instance, 6.347882043391421e-43, -3.3269628139999807e-41)),
        2147506937u,
        "f32.add(6.347882043391421e-43, -3.3269628139999807e-41)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m12_floatX5FmiscX2E0Export7_f64X2Eadd(&instance, 2.8461489375936755e-308, -5.130160608603642e-308)),
        9227994927942701939ull,
        "f64.add(2.8461489375936755e-308, -5.130160608603642e-308)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m12_floatX5FmiscX2E0Export7_f64X2Eadd(&instance, 4.7404811354775e-308, -8.895417776504167e-308)),
        9231781722239704866ull,
        "f64.add(4.7404811354775e-308, -8.895417776504167e-308)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m12_floatX5FmiscX2E0Export7_f64X2Eadd(&instance, -9.330082001250494e-309, -2.9863980609419717e-308)),
        9231305003443443272ull,
        "f64.add(-9.330082001250494e-309, -2.9863980609419717e-308)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m12_floatX5FmiscX2E0Export7_f64X2Eadd(&instance, 1.4418693884494008e-307, -1.6324914377759187e-307)),
        9227230270086150260ull,
        "f64.add(1.4418693884494008e-307, -1.6324914377759187e-307)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m12_floatX5FmiscX2E0Export7_f64X2Eadd(&instance, -4.3203619362281506e-308, 2.521511966399844e-308)),
        9227012949727326178ull,
        "f64.add(-4.3203619362281506e-308, 2.521511966399844e-308)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m12_floatX5FmiscX2E0Export7_f32X2Eadd(&instance, 3.4028232635611926e+38, 2.028240960365167e+31)),
        2139095039u,
        "f32.add(3.4028232635611926e+38, 2.028240960365167e+31)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m12_floatX5FmiscX2E0Export7_f64X2Eadd(&instance, 1.7976931348623155e+308, 1.99584030953472e+292)),
        9218868437227405311ull,
        "f64.add(1.7976931348623155e+308, 1.99584030953472e+292)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m12_floatX5FmiscX2E0Export7_f32X2Eadd(&instance, 2.0, 2.0)),
        1082130432u,
        "f32.add(2.0, 2.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m12_floatX5FmiscX2E0Export7_f64X2Eadd(&instance, 2.0, 2.0)),
        4616189618054758400ull,
        "f64.add(2.0, 2.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m12_floatX5FmiscX2E0Export7_f32X2Eadd(&instance, 3.4028234663852886e+38, 1.0141204197362925e+31)),
        2139095039u,
        "f32.add(3.4028234663852886e+38, 1.0141204197362925e+31)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m12_floatX5FmiscX2E0Export7_f32X2Eadd(&instance, 3.4028234663852886e+38, 1.0141204801825835e+31)),
        2139095040u,
        "f32.add(3.4028234663852886e+38, 1.0141204801825835e+31)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m12_floatX5FmiscX2E0Export7_f64X2Eadd(&instance, 1.7976931348623157e+308, 9.979201547673598e+291)),
        9218868437227405311ull,
        "f64.add(1.7976931348623157e+308, 9.979201547673598e+291)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m12_floatX5FmiscX2E0Export7_f64X2Eadd(&instance, 1.7976931348623157e+308, 9.9792015476736e+291)),
        9218868437227405312ull,
        "f64.add(1.7976931348623157e+308, 9.9792015476736e+291)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m12_floatX5FmiscX2E0Export7_f32X2Esub(&instance, 65536.0, 7.275957614183426e-12)),
        1199570944u,
        "f32.sub(65536.0, 7.275957614183426e-12)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m12_floatX5FmiscX2E0Export7_f64X2Esub(&instance, 65536.0, 7.275957614183426e-12)),
        4679240012837945343ull,
        "f64.sub(65536.0, 7.275957614183426e-12)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m12_floatX5FmiscX2E0Export7_f32X2Esub(&instance, 1.0, 2.9802322387695312e-08)),
        1065353216u,
        "f32.sub(1.0, 2.9802322387695312e-08)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m12_floatX5FmiscX2E0Export7_f32X2Esub(&instance, 1.0, 2.980232594040899e-08)),
        1065353215u,
        "f32.sub(1.0, 2.980232594040899e-08)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m12_floatX5FmiscX2E0Export7_f64X2Esub(&instance, 1.0, 5.551115123125783e-17)),
        4607182418800017408ull,
        "f64.sub(1.0, 5.551115123125783e-17)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m12_floatX5FmiscX2E0Export7_f64X2Esub(&instance, 1.0, 5.551115123125784e-17)),
        4607182418800017407ull,
        "f64.sub(1.0, 5.551115123125784e-17)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m12_floatX5FmiscX2E0Export7_f32X2Esub(&instance, 2.3792080598407964e-32, -7.221297616978506e+35)),
        2064323519u,
        "f32.sub(2.3792080598407964e-32, -7.221297616978506e+35)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m12_floatX5FmiscX2E0Export7_f32X2Esub(&instance, -8.422840238404834e+35, -11118414135296.0)),
        4213323727u,
        "f32.sub(-8.422840238404834e+35, -11118414135296.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m12_floatX5FmiscX2E0Export7_f32X2Esub(&instance, 1.454944372177124, -3.3792614555846486e-25)),
        1069169566u,
        "f32.sub(1.454944372177124, -3.3792614555846486e-25)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m12_floatX5FmiscX2E0Export7_f32X2Esub(&instance, 9.480891428414285e-36, 1.8589502498367712e-23)),
        2578696545u,
        "f32.sub(9.480891428414285e-36, 1.8589502498367712e-23)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m12_floatX5FmiscX2E0Export7_f32X2Esub(&instance, 6.18116700934479e-06, -9.395986424247663e-33)),
        919562194u,
        "f32.sub(6.18116700934479e-06, -9.395986424247663e-33)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m12_floatX5FmiscX2E0Export7_f64X2Esub(&instance, -7.75701650124413e-101, -2.524845082116609e-272)),
        12332465020357998661ull,
        "f64.sub(-7.75701650124413e-101, -2.524845082116609e-272)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m12_floatX5FmiscX2E0Export7_f64X2Esub(&instance, -2.099187106483271e+166, -3.8165079778426864e-48)),
        16318450733361321773ull,
        "f64.sub(-2.099187106483271e+166, -3.8165079778426864e-48)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m12_floatX5FmiscX2E0Export7_f64X2Esub(&instance, 2.8592030964162332e-139, -2.0889465194336087e-252)),
        2534186520144737456ull,
        "f64.sub(2.8592030964162332e-139, -2.0889465194336087e-252)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m12_floatX5FmiscX2E0Export7_f64X2Esub(&instance, 3.03879528930943e-303, -2.3204941114021897e+46)),
        5300809529500905193ull,
        "f64.sub(3.03879528930943e-303, -2.3204941114021897e+46)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m12_floatX5FmiscX2E0Export7_f64X2Esub(&instance, -1.4953904039036317e-43, -1.0592252695645683e-162)),
        13189545483472981053ull,
        "f64.sub(-1.4953904039036317e-43, -1.0592252695645683e-162)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m12_floatX5FmiscX2E0Export7_f32X2Esub(&instance, -4.486016552717641e+32, -8.984148050887244e+33)),
        2010278623u,
        "f32.sub(-4.486016552717641e+32, -8.984148050887244e+33)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m12_floatX5FmiscX2E0Export7_f32X2Esub(&instance, -8.994274245666093e+32, 91.57938385009766)),
        4130431355u,
        "f32.sub(-8.994274245666093e+32, 91.57938385009766)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m12_floatX5FmiscX2E0Export7_f32X2Esub(&instance, -1.1974999753297125e-25, 6.314040490451589e-08)),
        3012007886u,
        "f32.sub(-1.1974999753297125e-25, 6.314040490451589e-08)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m12_floatX5FmiscX2E0Export7_f32X2Esub(&instance, -1.1800486661945162e-23, -0.00031558735645376146)),
        967144811u,
        "f32.sub(-1.1800486661945162e-23, -0.00031558735645376146)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m12_floatX5FmiscX2E0Export7_f32X2Esub(&instance, -7.364838050540576e+29, 3.0824513295512927e-18)),
        4044667730u,
        "f32.sub(-7.364838050540576e+29, 3.0824513295512927e-18)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m12_floatX5FmiscX2E0Export7_f64X2Esub(&instance, -9.410469964196796e+60, -1.730627569138597e+271)),
        8665032469553408441ull,
        "f64.sub(-9.410469964196796e+60, -1.730627569138597e+271)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m12_floatX5FmiscX2E0Export7_f64X2Esub(&instance, 2.877908564233173e-111, 2.339448785991429e-136)),
        2953146626865245854ull,
        "f64.sub(2.877908564233173e-111, 2.339448785991429e-136)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m12_floatX5FmiscX2E0Export7_f64X2Esub(&instance, -9.719219783531962e-61, 1.572015082308034e-153)),
        12932364735331397407ull,
        "f64.sub(-9.719219783531962e-61, 1.572015082308034e-153)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m12_floatX5FmiscX2E0Export7_f64X2Esub(&instance, -3.4908896031751274e-299, -1.9928479721303208e-99)),
        3130405779404271166ull,
        "f64.sub(-3.4908896031751274e-299, -1.9928479721303208e-99)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m12_floatX5FmiscX2E0Export7_f64X2Esub(&instance, -7.538298763725556e+33, 4.447012580193329e+51)),
        14602857513160325252ull,
        "f64.sub(-7.538298763725556e+33, 4.447012580193329e+51)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m12_floatX5FmiscX2E0Export7_f32X2Esub(&instance, 7.584697644672857e+28, 4.6391753130592406e-05)),
        1869943590u,
        "f32.sub(7.584697644672857e+28, 4.6391753130592406e-05)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m12_floatX5FmiscX2E0Export7_f32X2Esub(&instance, -567139.875, -3.0334842276991125e-11)),
        3372906046u,
        "f32.sub(-567139.875, -3.0334842276991125e-11)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m12_floatX5FmiscX2E0Export7_f32X2Esub(&instance, -1.741226086926506e-11, -1.7877793367743258e-17)),
        2912495843u,
        "f32.sub(-1.741226086926506e-11, -1.7877793367743258e-17)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m12_floatX5FmiscX2E0Export7_f32X2Esub(&instance, -6.564554496435449e-05, 0.0001447380636818707)),
        3109853804u,
        "f32.sub(-6.564554496435449e-05, 0.0001447380636818707)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m12_floatX5FmiscX2E0Export7_f32X2Esub(&instance, -1.601611482326959e-10, -8.538007497388273e-32)),
        2939165019u,
        "f32.sub(-1.601611482326959e-10, -8.538007497388273e-32)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m12_floatX5FmiscX2E0Export7_f64X2Esub(&instance, -9.358725267183177e-48, -3.1137147338685164e+217)),
        7860633718497577448ull,
        "f64.sub(-9.358725267183177e-48, -3.1137147338685164e+217)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m12_floatX5FmiscX2E0Export7_f64X2Esub(&instance, -4.390767596767215e+228, -6.789045715895856e+271)),
        8673950781521113021ull,
        "f64.sub(-4.390767596767215e+228, -6.789045715895856e+271)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m12_floatX5FmiscX2E0Export7_f64X2Esub(&instance, 3.6288281010831153e-240, 3.3831996832450044e+54)),
        14646173553725680315ull,
        "f64.sub(3.6288281010831153e-240, 3.3831996832450044e+54)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m12_floatX5FmiscX2E0Export7_f64X2Esub(&instance, -3.645097751812619e-173, 3.1423490969686624e-164)),
        11384242175310282886ull,
        "f64.sub(-3.645097751812619e-173, 3.1423490969686624e-164)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m12_floatX5FmiscX2E0Export7_f64X2Esub(&instance, -8.021529638989887e-169, -6.774972769072139e-05)),
        4544627471940556971ull,
        "f64.sub(-8.021529638989887e-169, -6.774972769072139e-05)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m12_floatX5FmiscX2E0Export7_f64X2Esub(&instance, 5.816988065793039e-24, 2.5021499241540866e-35)),
        4259315722107229795ull,
        "f64.sub(5.816988065793039e-24, 2.5021499241540866e-35)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m12_floatX5FmiscX2E0Export7_f64X2Esub(&instance, 4.3336683304809554e-296, 1.6945582607476316e-304)),
        188121565409457039ull,
        "f64.sub(4.3336683304809554e-296, 1.6945582607476316e-304)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m12_floatX5FmiscX2E0Export7_f64X2Esub(&instance, 6.908052676315257e-77, 1.2001773734799856e-60)),
        12934016620898986161ull,
        "f64.sub(6.908052676315257e-77, 1.2001773734799856e-60)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m12_floatX5FmiscX2E0Export7_f64X2Esub(&instance, -2.2044291547443813e-12, -2.7947429925618632e-21)),
        13655868372781906121ull,
        "f64.sub(-2.2044291547443813e-12, -2.7947429925618632e-21)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m12_floatX5FmiscX2E0Export7_f64X2Esub(&instance, 4.016393569117761e-08, 0.17053881989395447)),
        13818684364224065885ull,
        "f64.sub(4.016393569117761e-08, 0.17053881989395447)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m12_floatX5FmiscX2E0Export7_f64X2Esub(&instance, -1.0015106898667285e-245, -4.785375958943186e-231)),
        1161286245958284573ull,
        "f64.sub(-1.0015106898667285e-245, -4.785375958943186e-231)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m12_floatX5FmiscX2E0Export7_f64X2Esub(&instance, -15618959953.641388, 5.982344106207189e+110)),
        15487834286935646730ull,
        "f64.sub(-15618959953.641388, 5.982344106207189e+110)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m12_floatX5FmiscX2E0Export7_f64X2Esub(&instance, 3.883207154037668e+34, 4.2192279274320304e-178)),
        5124509539958121241ull,
        "f64.sub(3.883207154037668e+34, 4.2192279274320304e-178)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m12_floatX5FmiscX2E0Export7_f64X2Esub(&instance, 1.0705986890807897e-147, -1.7466607734737216e-209)),
        2408125051325635052ull,
        "f64.sub(1.0705986890807897e-147, -1.7466607734737216e-209)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m12_floatX5FmiscX2E0Export7_f64X2Esub(&instance, 9.49378346261834e-18, 1.4584885434950294e-186)),
        4352135458168599028ull,
        "f64.sub(9.49378346261834e-18, 1.4584885434950294e-186)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m12_floatX5FmiscX2E0Export7_f32X2Esub(&instance, 23.14069175720215, 3.1415927410125732)),
        1101004328u,
        "f32.sub(23.14069175720215, 3.1415927410125732)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m12_floatX5FmiscX2E0Export7_f64X2Esub(&instance, 23.14069263277927, 3.141592653589793)),
        4626322463883005335ull,
        "f64.sub(23.14069263277927, 3.141592653589793)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m12_floatX5FmiscX2E0Export7_f32X2Esub(&instance, 2999999.0, 2999998.0)),
        1065353216u,
        "f32.sub(2999999.0, 2999998.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m12_floatX5FmiscX2E0Export7_f32X2Esub(&instance, 1999999.0, 1999995.0)),
        1082130432u,
        "f32.sub(1999999.0, 1999995.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m12_floatX5FmiscX2E0Export7_f32X2Esub(&instance, 1999999.0, 1999993.0)),
        1086324736u,
        "f32.sub(1999999.0, 1999993.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m12_floatX5FmiscX2E0Export7_f32X2Esub(&instance, 400002.0, 400001.0)),
        1065353216u,
        "f32.sub(400002.0, 400001.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m12_floatX5FmiscX2E0Export7_f32X2Esub(&instance, 400002.0, 400000.0)),
        1073741824u,
        "f32.sub(400002.0, 400000.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m12_floatX5FmiscX2E0Export7_f64X2Esub(&instance, 2999999999999999.0, 2999999999999998.0)),
        4607182418800017408ull,
        "f64.sub(2999999999999999.0, 2999999999999998.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m12_floatX5FmiscX2E0Export7_f64X2Esub(&instance, 1999999999999999.0, 1999999999999995.0)),
        4616189618054758400ull,
        "f64.sub(1999999999999999.0, 1999999999999995.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m12_floatX5FmiscX2E0Export7_f64X2Esub(&instance, 1999999999999999.0, 1999999999999993.0)),
        4618441417868443648ull,
        "f64.sub(1999999999999999.0, 1999999999999993.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m12_floatX5FmiscX2E0Export7_f64X2Esub(&instance, 400000000000002.0, 400000000000001.0)),
        4607182418800017408ull,
        "f64.sub(400000000000002.0, 400000000000001.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m12_floatX5FmiscX2E0Export7_f64X2Esub(&instance, 400000000000002.0, 400000000000000.0)),
        4611686018427387904ull,
        "f64.sub(400000000000002.0, 400000000000000.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m12_floatX5FmiscX2E0Export7_f32X2Esub(&instance, 1.1754943508222875e-38, 1.1754942106924411e-38)),
        1u,
        "f32.sub(1.1754943508222875e-38, 1.1754942106924411e-38)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m12_floatX5FmiscX2E0Export7_f64X2Esub(&instance, 2.2250738585072014e-308, 2.225073858507201e-308)),
        1ull,
        "f64.sub(2.2250738585072014e-308, 2.225073858507201e-308)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m12_floatX5FmiscX2E0Export7_f32X2Esub(&instance, 1.0000001192092896, 0.9999999403953552)),
        876609536u,
        "f32.sub(1.0000001192092896, 0.9999999403953552)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m12_floatX5FmiscX2E0Export7_f32X2Esub(&instance, 1.0000001192092896, 1.0)),
        872415232u,
        "f32.sub(1.0000001192092896, 1.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m12_floatX5FmiscX2E0Export7_f32X2Esub(&instance, 1.0, 0.9999999403953552)),
        864026624u,
        "f32.sub(1.0, 0.9999999403953552)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m12_floatX5FmiscX2E0Export7_f64X2Esub(&instance, 1.0000000000000002, 0.9999999999999999)),
        4375247037990436864ull,
        "f64.sub(1.0000000000000002, 0.9999999999999999)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m12_floatX5FmiscX2E0Export7_f64X2Esub(&instance, 1.0000000000000002, 1.0)),
        4372995238176751616ull,
        "f64.sub(1.0000000000000002, 1.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m12_floatX5FmiscX2E0Export7_f64X2Esub(&instance, 1.0, 0.9999999999999999)),
        4368491638549381120ull,
        "f64.sub(1.0, 0.9999999999999999)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m12_floatX5FmiscX2E0Export7_f32X2Esub(&instance, 3.4028234663852886e+38, 1.0141204197362925e+31)),
        2139095039u,
        "f32.sub(3.4028234663852886e+38, 1.0141204197362925e+31)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m12_floatX5FmiscX2E0Export7_f32X2Esub(&instance, 3.4028234663852886e+38, 1.0141204801825835e+31)),
        2139095038u,
        "f32.sub(3.4028234663852886e+38, 1.0141204801825835e+31)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m12_floatX5FmiscX2E0Export7_f64X2Esub(&instance, 1.7976931348623157e+308, 9.979201547673598e+291)),
        9218868437227405311ull,
        "f64.sub(1.7976931348623157e+308, 9.979201547673598e+291)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m12_floatX5FmiscX2E0Export7_f64X2Esub(&instance, 1.7976931348623157e+308, 9.9792015476736e+291)),
        9218868437227405310ull,
        "f64.sub(1.7976931348623157e+308, 9.9792015476736e+291)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m12_floatX5FmiscX2E0Export7_f32X2Emul(&instance, 999999986991104.0, 999999986991104.0)),
        1900671689u,
        "f32.mul(999999986991104.0, 999999986991104.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m12_floatX5FmiscX2E0Export7_f32X2Emul(&instance, 1.0000000200408773e+20, 1.0000000200408773e+20)),
        2139095040u,
        "f32.mul(1.0000000200408773e+20, 1.0000000200408773e+20)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m12_floatX5FmiscX2E0Export7_f32X2Emul(&instance, 9.999999562023526e+24, 9.999999562023526e+24)),
        2139095040u,
        "f32.mul(9.999999562023526e+24, 9.999999562023526e+24)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m12_floatX5FmiscX2E0Export7_f64X2Emul(&instance, 1000000000000000.0, 1000000000000000.0)),
        5055640609639927018ull,
        "f64.mul(1000000000000000.0, 1000000000000000.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m12_floatX5FmiscX2E0Export7_f64X2Emul(&instance, 1e+20, 1e+20)),
        5205425776111082661ull,
        "f64.mul(1e+20, 1e+20)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m12_floatX5FmiscX2E0Export7_f64X2Emul(&instance, 1e+25, 1e+25)),
        5355091182177117339ull,
        "f64.mul(1e+25, 1e+25)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m12_floatX5FmiscX2E0Export7_f32X2Emul(&instance, 1848874880.0, 19954563072.0)),
        1610612737u,
        "f32.mul(1848874880.0, 19954563072.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m12_floatX5FmiscX2E0Export7_f64X2Emul(&instance, 1848874847.0, 19954562207.0)),
        4899916394579099649ull,
        "f64.mul(1848874847.0, 19954562207.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m12_floatX5FmiscX2E0Export7_f32X2Emul(&instance, 77.0999984741211, 850.0)),
        1199570688u,
        "f32.mul(77.0999984741211, 850.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m12_floatX5FmiscX2E0Export7_f64X2Emul(&instance, 77.1, 850.0)),
        4679239875398991871ull,
        "f64.mul(77.1, 850.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m12_floatX5FmiscX2E0Export7_f32X2Emul(&instance, -2.493839431476183e+18, 2.1176053965898944e-11)),
        3427365876u,
        "f32.mul(-2.493839431476183e+18, 2.1176053965898944e-11)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m12_floatX5FmiscX2E0Export7_f32X2Emul(&instance, -6.777248420629078e+30, -3.4758241830226954e-31)),
        1075233538u,
        "f32.mul(-6.777248420629078e+30, -3.4758241830226954e-31)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m12_floatX5FmiscX2E0Export7_f32X2Emul(&instance, -8.384397588099775e+27, -1.1948990730232888e-29)),
        1036856791u,
        "f32.mul(-8.384397588099775e+27, -1.1948990730232888e-29)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m12_floatX5FmiscX2E0Export7_f32X2Emul(&instance, -6.567654100365863e+23, -4.6889765988592106e-23)),
        1106664791u,
        "f32.mul(-6.567654100365863e+23, -4.6889765988592106e-23)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m12_floatX5FmiscX2E0Export7_f32X2Emul(&instance, 1.3328203716231168e+16, 45.567222595214844)),
        1560730283u,
        "f32.mul(1.3328203716231168e+16, 45.567222595214844)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m12_floatX5FmiscX2E0Export7_f64X2Emul(&instance, -9.942622609334243e+127, 5.8317724151424514e+284)),
        18442240474082181120ull,
        "f64.mul(-9.942622609334243e+127, 5.8317724151424514e+284)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m12_floatX5FmiscX2E0Export7_f64X2Emul(&instance, -2.748155824301909e-297, -2.093035437779455e-66)),
        0ull,
        "f64.mul(-2.748155824301909e-297, -2.093035437779455e-66)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m12_floatX5FmiscX2E0Export7_f64X2Emul(&instance, 4.648882573713025e+182, -1.5927288648725436e+32)),
        17044856006279008467ull,
        "f64.mul(4.648882573713025e+182, -1.5927288648725436e+32)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m12_floatX5FmiscX2E0Export7_f64X2Emul(&instance, -8.261927764172427e-95, 3.6684744190529535e+175)),
        15049217706304651865ull,
        "f64.mul(-8.261927764172427e-95, 3.6684744190529535e+175)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m12_floatX5FmiscX2E0Export7_f64X2Emul(&instance, 2.5383895833176925e+239, 7.842892881810105e-259)),
        4327221634240578200ull,
        "f64.mul(2.5383895833176925e+239, 7.842892881810105e-259)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m12_floatX5FmiscX2E0Export7_f32X2Emul(&instance, -2.0153333457426413e-27, -5.031353283027048e+27)),
        1092762840u,
        "f32.mul(-2.0153333457426413e-27, -5.031353283027048e+27)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m12_floatX5FmiscX2E0Export7_f32X2Emul(&instance, 1.2286325312524885e+22, 749601.8125)),
        1844318640u,
        "f32.mul(1.2286325312524885e+22, 749601.8125)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m12_floatX5FmiscX2E0Export7_f32X2Emul(&instance, -2.7635138621917577e-10, -3.5524713616272016e+22)),
        1427037263u,
        "f32.mul(-2.7635138621917577e-10, -3.5524713616272016e+22)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m12_floatX5FmiscX2E0Export7_f32X2Emul(&instance, 2.189312192933622e+20, -40298.78515625)),
        3907618991u,
        "f32.mul(2.189312192933622e+20, -40298.78515625)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m12_floatX5FmiscX2E0Export7_f32X2Emul(&instance, 1691996288.0, -1.2210335231587333e+20)),
        4029080461u,
        "f32.mul(1691996288.0, -1.2210335231587333e+20)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m12_floatX5FmiscX2E0Export7_f64X2Emul(&instance, -7.576316076452304e-193, 4.601355879514986e-95)),
        9544600684599159351ull,
        "f64.mul(-7.576316076452304e-193, 4.601355879514986e-95)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m12_floatX5FmiscX2E0Export7_f64X2Emul(&instance, 1.2228616081443885e-83, -8.055526185180067e-192)),
        9730951521726442211ull,
        "f64.mul(1.2228616081443885e-83, -8.055526185180067e-192)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m12_floatX5FmiscX2E0Export7_f64X2Emul(&instance, -2.0686512460392508e+99, -3.668010715832548e+251)),
        9218868437227405312ull,
        "f64.mul(-2.0686512460392508e+99, -3.668010715832548e+251)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m12_floatX5FmiscX2E0Export7_f64X2Emul(&instance, 1.543238835610281e+285, 7.370621385787007e-133)),
        6896620497836925834ull,
        "f64.mul(1.543238835610281e+285, 7.370621385787007e-133)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m12_floatX5FmiscX2E0Export7_f64X2Emul(&instance, 2.2358765662420587e+102, -7.60669005920257e+50)),
        16122953269734234204ull,
        "f64.mul(2.2358765662420587e+102, -7.60669005920257e+50)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m12_floatX5FmiscX2E0Export7_f32X2Emul(&instance, -110087033061376.0, -5.403802077401142e+28)),
        2139095040u,
        "f32.mul(-110087033061376.0, -5.403802077401142e+28)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m12_floatX5FmiscX2E0Export7_f32X2Emul(&instance, -0.19366350769996643, 2.9748953998406853e-30)),
        2369451750u,
        "f32.mul(-0.19366350769996643, 2.9748953998406853e-30)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m12_floatX5FmiscX2E0Export7_f32X2Emul(&instance, -3.4300712741242023e-06, 7.799152327916086e+31)),
        3948759250u,
        "f32.mul(-3.4300712741242023e-06, 7.799152327916086e+31)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m12_floatX5FmiscX2E0Export7_f32X2Emul(&instance, -9.900384948584448e+16, 2.0933773655262767e-29)),
        2886850375u,
        "f32.mul(-9.900384948584448e+16, 2.0933773655262767e-29)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m12_floatX5FmiscX2E0Export7_f32X2Emul(&instance, -129919.0703125, 1.8480998564440598e-36)),
        2359023110u,
        "f32.mul(-129919.0703125, 1.8480998564440598e-36)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m12_floatX5FmiscX2E0Export7_f64X2Emul(&instance, -6.625572200844895e-150, -3.737402068174001e+130)),
        4328598597203697163ull,
        "f64.mul(-6.625572200844895e-150, -3.737402068174001e+130)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m12_floatX5FmiscX2E0Export7_f64X2Emul(&instance, 8.21076848561758e+143, -1.2976552328552289e-230)),
        12543987340819631453ull,
        "f64.mul(8.21076848561758e+143, -1.2976552328552289e-230)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m12_floatX5FmiscX2E0Export7_f64X2Emul(&instance, -1.0223449294906041e+52, 1.9708555833346805e+108)),
        16228420234814429284ull,
        "f64.mul(-1.0223449294906041e+52, 1.9708555833346805e+108)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m12_floatX5FmiscX2E0Export7_f64X2Emul(&instance, 2.918243080119086e+231, -6.36331709416897e+112)),
        18442240474082181120ull,
        "f64.mul(2.918243080119086e+231, -6.36331709416897e+112)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m12_floatX5FmiscX2E0Export7_f64X2Emul(&instance, 3.407037798802672e+24, 1.225791423971563e+21)),
        5289311430451755328ull,
        "f64.mul(3.407037798802672e+24, 1.225791423971563e+21)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m12_floatX5FmiscX2E0Export7_f64X2Emul(&instance, 4.4091927284399547e-103, 1.1518840702296592e-173)),
        488220554609224151ull,
        "f64.mul(4.4091927284399547e-103, 1.1518840702296592e-173)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m12_floatX5FmiscX2E0Export7_f64X2Emul(&instance, -0.002980041826472432, 6.3125412993218e+217)),
        17051039770050770421ull,
        "f64.mul(-0.002980041826472432, 6.3125412993218e+217)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m12_floatX5FmiscX2E0Export7_f64X2Emul(&instance, -3.083445780813001e+110, -1.0081049555008529e-196)),
        3327855557076626973ull,
        "f64.mul(-3.083445780813001e+110, -1.0081049555008529e-196)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m12_floatX5FmiscX2E0Export7_f64X2Emul(&instance, 3.493875013156773e+233, 2.1313169159308099e+18)),
        8375006889399652877ull,
        "f64.mul(3.493875013156773e+233, 2.1313169159308099e+18)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m12_floatX5FmiscX2E0Export7_f64X2Emul(&instance, -1.2500108005100234e-83, 1.0352657041604675e+270)),
        16629483498509877989ull,
        "f64.mul(-1.2500108005100234e-83, 1.0352657041604675e+270)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m12_floatX5FmiscX2E0Export7_f64X2Emul(&instance, 8.947461661755698e-181, 2.0853844141312436e-128)),
        3776602816350777ull,
        "f64.mul(8.947461661755698e-181, 2.0853844141312436e-128)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m12_floatX5FmiscX2E0Export7_f64X2Emul(&instance, -1.161813037330394e-17, -1.8737038135583668e-291)),
        4406081533924885ull,
        "f64.mul(-1.161813037330394e-17, -1.8737038135583668e-291)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m12_floatX5FmiscX2E0Export7_f64X2Emul(&instance, -2.1752326768352433e-147, -6.631210068072052e-162)),
        2919536087652621ull,
        "f64.mul(-2.1752326768352433e-147, -6.631210068072052e-162)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m12_floatX5FmiscX2E0Export7_f64X2Emul(&instance, -7.149518157441743e-233, 2.2770445062365393e-77)),
        9223701543089011575ull,
        "f64.mul(-7.149518157441743e-233, 2.2770445062365393e-77)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m12_floatX5FmiscX2E0Export7_f64X2Emul(&instance, -4.817739302150786e-156, -2.5375023049719763e-153)),
        2474372522531115ull,
        "f64.mul(-4.817739302150786e-156, -2.5375023049719763e-153)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m12_floatX5FmiscX2E0Export7_f64X2Emul(&instance, 4.6576441629501554e+256, 7.021344893525714e-266)),
        4479981512316931443ull,
        "f64.mul(4.6576441629501554e+256, 7.021344893525714e-266)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m12_floatX5FmiscX2E0Export7_f64X2Emul(&instance, 0.012451716278313712, 1.945309177849331e-45)),
        3909603143436010489ull,
        "f64.mul(0.012451716278313712, 1.945309177849331e-45)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m12_floatX5FmiscX2E0Export7_f64X2Emul(&instance, -3.8312314777598586, 9.039887741742674e-13)),
        13658985409477228135ull,
        "f64.mul(-3.8312314777598586, 9.039887741742674e-13)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m12_floatX5FmiscX2E0Export7_f64X2Emul(&instance, 9.843582638849689e-113, 3.375405654777583e-62)),
        2011503789135851990ull,
        "f64.mul(9.843582638849689e-113, 3.375405654777583e-62)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m12_floatX5FmiscX2E0Export7_f64X2Emul(&instance, -2.6054453709451446e+23, 3.2887528185809035e-105)),
        12617399980269247921ull,
        "f64.mul(-2.6054453709451446e+23, 3.2887528185809035e-105)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m12_floatX5FmiscX2E0Export7_f32X2Emul(&instance, 2.6469779601696886e-23, 2.6469779601696886e-23)),
        0u,
        "f32.mul(2.6469779601696886e-23, 2.6469779601696886e-23)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m12_floatX5FmiscX2E0Export7_f32X2Emul(&instance, 2.6469782757140506e-23, 2.6469782757140506e-23)),
        1u,
        "f32.mul(2.6469782757140506e-23, 2.6469782757140506e-23)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m12_floatX5FmiscX2E0Export7_f64X2Emul(&instance, 1.5717277847026285e-162, 1.5717277847026285e-162)),
        0ull,
        "f64.mul(1.5717277847026285e-162, 1.5717277847026285e-162)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m12_floatX5FmiscX2E0Export7_f64X2Emul(&instance, 1.5717277847026288e-162, 1.5717277847026288e-162)),
        1ull,
        "f64.mul(1.5717277847026288e-162, 1.5717277847026288e-162)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m12_floatX5FmiscX2E0Export7_f32X2Emul(&instance, 1.8446742974197924e+19, 1.8446742974197924e+19)),
        2139095038u,
        "f32.mul(1.8446742974197924e+19, 1.8446742974197924e+19)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m12_floatX5FmiscX2E0Export7_f32X2Emul(&instance, 1.8446744073709552e+19, 1.8446744073709552e+19)),
        2139095040u,
        "f32.mul(1.8446744073709552e+19, 1.8446744073709552e+19)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m12_floatX5FmiscX2E0Export7_f64X2Emul(&instance, 1.3407807929942596e+154, 1.3407807929942596e+154)),
        9218868437227405310ull,
        "f64.mul(1.3407807929942596e+154, 1.3407807929942596e+154)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m12_floatX5FmiscX2E0Export7_f64X2Emul(&instance, 1.3407807929942597e+154, 1.3407807929942597e+154)),
        9218868437227405312ull,
        "f64.mul(1.3407807929942597e+154, 1.3407807929942597e+154)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m12_floatX5FmiscX2E0Export7_f32X2Emul(&instance, 1.0000001192092896, 1.0000001192092896)),
        1065353218u,
        "f32.mul(1.0000001192092896, 1.0000001192092896)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m12_floatX5FmiscX2E0Export7_f32X2Emul(&instance, 0.9999999403953552, 0.9999999403953552)),
        1065353214u,
        "f32.mul(0.9999999403953552, 0.9999999403953552)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m12_floatX5FmiscX2E0Export7_f64X2Emul(&instance, 1.0000000000000002, 1.0000000000000002)),
        4607182418800017410ull,
        "f64.mul(1.0000000000000002, 1.0000000000000002)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m12_floatX5FmiscX2E0Export7_f64X2Emul(&instance, 0.9999999999999999, 0.9999999999999999)),
        4607182418800017406ull,
        "f64.mul(0.9999999999999999, 0.9999999999999999)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m12_floatX5FmiscX2E0Export7_f32X2Emul(&instance, 1.0000001192092896, 0.9999999403953552)),
        1065353216u,
        "f32.mul(1.0000001192092896, 0.9999999403953552)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m12_floatX5FmiscX2E0Export7_f32X2Emul(&instance, 1.000000238418579, 0.9999998807907104)),
        1065353217u,
        "f32.mul(1.000000238418579, 0.9999998807907104)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m12_floatX5FmiscX2E0Export7_f64X2Emul(&instance, 1.0000000000000002, 0.9999999999999999)),
        4607182418800017408ull,
        "f64.mul(1.0000000000000002, 0.9999999999999999)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m12_floatX5FmiscX2E0Export7_f64X2Emul(&instance, 1.0000000000000004, 0.9999999999999998)),
        4607182418800017409ull,
        "f64.mul(1.0000000000000004, 0.9999999999999998)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m12_floatX5FmiscX2E0Export7_f32X2Emul(&instance, 1.1754943508222875e-38, 1.1920928955078125e-07)),
        1u,
        "f32.mul(1.1754943508222875e-38, 1.1920928955078125e-07)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m12_floatX5FmiscX2E0Export7_f64X2Emul(&instance, 2.2250738585072014e-308, 2.220446049250313e-16)),
        1ull,
        "f64.mul(2.2250738585072014e-308, 2.220446049250313e-16)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m12_floatX5FmiscX2E0Export7_f32X2Emul(&instance, -16.00146484375, 2.9846536251347144e-40)),
        2150891832u,
        "f32.mul(-16.00146484375, 2.9846536251347144e-40)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m12_floatX5FmiscX2E0Export7_f32X2Ediv(&instance, 1.1234568357467651, 100.0)),
        1010307378u,
        "f32.div(1.1234568357467651, 100.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m12_floatX5FmiscX2E0Export7_f32X2Ediv(&instance, 8391667.0, 12582905.0)),
        1059764896u,
        "f32.div(8391667.0, 12582905.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m12_floatX5FmiscX2E0Export7_f32X2Ediv(&instance, 65536.0, 7.275957614183426e-12)),
        1509949440u,
        "f32.div(65536.0, 7.275957614183426e-12)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m12_floatX5FmiscX2E0Export7_f32X2Ediv(&instance, 1.8622957468032837, 3.4028234663852886e+38)),
        3905517u,
        "f32.div(1.8622957468032837, 3.4028234663852886e+38)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m12_floatX5FmiscX2E0Export7_f32X2Ediv(&instance, 4.0, 3.0)),
        1068149419u,
        "f32.div(4.0, 3.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m12_floatX5FmiscX2E0Export7_f64X2Ediv(&instance, 1.123456789, 100.0)),
        4577629909238726725ull,
        "f64.div(1.123456789, 100.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m12_floatX5FmiscX2E0Export7_f64X2Ediv(&instance, 8391667.0, 12582905.0)),
        4604182212107680295ull,
        "f64.div(8391667.0, 12582905.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m12_floatX5FmiscX2E0Export7_f64X2Ediv(&instance, 65536.0, 7.275957614183426e-12)),
        4845873199050653696ull,
        "f64.div(65536.0, 7.275957614183426e-12)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m12_floatX5FmiscX2E0Export7_f64X2Ediv(&instance, 1.8622957468032837, 1.7976931348623157e+308)),
        2096758607839232ull,
        "f64.div(1.8622957468032837, 1.7976931348623157e+308)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m12_floatX5FmiscX2E0Export7_f64X2Ediv(&instance, 4.0, 3.0)),
        4608683618675807573ull,
        "f64.div(4.0, 3.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m12_floatX5FmiscX2E0Export7_f32X2Ediv(&instance, 4195835.0, 3145727.0)),
        1068153505u,
        "f32.div(4195835.0, 3145727.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m12_floatX5FmiscX2E0Export7_f64X2Ediv(&instance, 4195835.0, 3145727.0)),
        4608685812450356035ull,
        "f64.div(4195835.0, 3145727.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m12_floatX5FmiscX2E0Export7_f32X2Ediv(&instance, 5.029632936401568e-15, 3.3632437638124346e+38)),
        0u,
        "f32.div(5.029632936401568e-15, 3.3632437638124346e+38)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m12_floatX5FmiscX2E0Export7_f32X2Ediv(&instance, 8.921986793542511e-27, 3.540975262112143e+20)),
        0u,
        "f32.div(8.921986793542511e-27, 3.540975262112143e+20)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m12_floatX5FmiscX2E0Export7_f32X2Ediv(&instance, -104167.46875, 1.5866622669037328e-24)),
        4015268357u,
        "f32.div(-104167.46875, 1.5866622669037328e-24)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m12_floatX5FmiscX2E0Export7_f32X2Ediv(&instance, -2.4938657382648078e-23, -3.6230087506368875e-37)),
        1450863298u,
        "f32.div(-2.4938657382648078e-23, -3.6230087506368875e-37)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m12_floatX5FmiscX2E0Export7_f32X2Ediv(&instance, -4142204190720.0, 1.1954948388200605e-24)),
        4230402947u,
        "f32.div(-4142204190720.0, 1.1954948388200605e-24)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m12_floatX5FmiscX2E0Export7_f64X2Ediv(&instance, 1.9390116382448384e+44, 2.5290742357348314e+67)),
        4261119458085367075ull,
        "f64.div(1.9390116382448384e+44, 2.5290742357348314e+67)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m12_floatX5FmiscX2E0Export7_f64X2Ediv(&instance, 6.600332149752304e-189, 3.007915153468629e-293)),
        6167818452243445017ull,
        "f64.div(6.600332149752304e-189, 3.007915153468629e-293)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m12_floatX5FmiscX2E0Export7_f64X2Ediv(&instance, -9.348275173661903e+89, 4.809309529035847e+192)),
        12293662509603441500ull,
        "f64.div(-9.348275173661903e+89, 4.809309529035847e+192)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m12_floatX5FmiscX2E0Export7_f64X2Ediv(&instance, -1.7598339088417535e+208, 1.9938607258068285e+74)),
        15834399302320062011ull,
        "f64.div(-1.7598339088417535e+208, 1.9938607258068285e+74)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m12_floatX5FmiscX2E0Export7_f64X2Ediv(&instance, -4.566268877844991e+162, 3.128249582233453e+136)),
        14221856927329063502ull,
        "f64.div(-4.566268877844991e+162, 3.128249582233453e+136)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m12_floatX5FmiscX2E0Export7_f32X2Ediv(&instance, -1.0394063760428808e+21, -1.2965965897989387e-26)),
        2139095040u,
        "f32.div(-1.0394063760428808e+21, -1.2965965897989387e-26)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m12_floatX5FmiscX2E0Export7_f32X2Ediv(&instance, 2.6831562620062248e-14, 31241038462976.0)),
        310908762u,
        "f32.div(2.6831562620062248e-14, 31241038462976.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m12_floatX5FmiscX2E0Export7_f32X2Ediv(&instance, 1.273424744606018, -6.927837068229471e+26)),
        2467406247u,
        "f32.div(1.273424744606018, -6.927837068229471e+26)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m12_floatX5FmiscX2E0Export7_f32X2Ediv(&instance, 6.898882714456895e-16, 3.762675552004818e-39)),
        1713065419u,
        "f32.div(6.898882714456895e-16, 3.762675552004818e-39)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m12_floatX5FmiscX2E0Export7_f32X2Ediv(&instance, 1.8199162204928903e+27, 2.050670305246714e+26)),
        1091436270u,
        "f32.div(1.8199162204928903e+27, 2.050670305246714e+26)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m12_floatX5FmiscX2E0Export7_f64X2Ediv(&instance, 2.1137715924428077e-308, -1.6733261612910253e+109)),
        9223372036854775808ull,
        "f64.div(2.1137715924428077e-308, -1.6733261612910253e+109)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m12_floatX5FmiscX2E0Export7_f64X2Ediv(&instance, -8.116644948016275e-298, 6.517571349002277e-162)),
        11796946241575527184ull,
        "f64.div(-8.116644948016275e-298, 6.517571349002277e-162)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m12_floatX5FmiscX2E0Export7_f64X2Ediv(&instance, -9.335476912259029e-122, -39099281466396.5)),
        2592881844429368931ull,
        "f64.div(-9.335476912259029e-122, -39099281466396.5)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m12_floatX5FmiscX2E0Export7_f64X2Ediv(&instance, -1.6868569854885902e+24, 1.3535993861076857e-238)),
        17751311910175316838ull,
        "f64.div(-1.6868569854885902e+24, 1.3535993861076857e-238)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m12_floatX5FmiscX2E0Export7_f64X2Ediv(&instance, -1.733887733249412e+71, -7.002616047521747e+16)),
        5420603229995464966ull,
        "f64.div(-1.733887733249412e+71, -7.002616047521747e+16)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m12_floatX5FmiscX2E0Export7_f32X2Ediv(&instance, 93506192.0, 2.87608846381627e-36)),
        2139095040u,
        "f32.div(93506192.0, 2.87608846381627e-36)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m12_floatX5FmiscX2E0Export7_f32X2Ediv(&instance, -2.0057539346671753e+23, 246697216.0)),
        3627605330u,
        "f32.div(-2.0057539346671753e+23, 246697216.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m12_floatX5FmiscX2E0Export7_f32X2Ediv(&instance, 384712212480.0, -1.0703784816622988e+29)),
        2726599162u,
        "f32.div(384712212480.0, -1.0703784816622988e+29)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m12_floatX5FmiscX2E0Export7_f32X2Ediv(&instance, -4.156665003774592e+33, -901.419189453125)),
        1919471347u,
        "f32.div(-4.156665003774592e+33, -901.419189453125)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m12_floatX5FmiscX2E0Export7_f32X2Ediv(&instance, -6.702386865118696e+27, -14000.2548828125)),
        1724563548u,
        "f32.div(-6.702386865118696e+27, -14000.2548828125)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m12_floatX5FmiscX2E0Export7_f64X2Ediv(&instance, -1.0085269598907525e-197, 1.8780374032850215e-208)),
        13990715555071506017ull,
        "f64.div(-1.0085269598907525e-197, 1.8780374032850215e-208)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m12_floatX5FmiscX2E0Export7_f64X2Ediv(&instance, -3.25716645629511e+235, -5.885738519211168e-167)),
        9218868437227405312ull,
        "f64.div(-3.25716645629511e+235, -5.885738519211168e-167)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m12_floatX5FmiscX2E0Export7_f64X2Ediv(&instance, -3.1640946861233317e-225, 4.5854510556516254e-20)),
        10760831595995331201ull,
        "f64.div(-3.1640946861233317e-225, 4.5854510556516254e-20)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m12_floatX5FmiscX2E0Export7_f64X2Ediv(&instance, -5.268422429466566e+95, -1.4816907071451201e-177)),
        8684356686754640262ull,
        "f64.div(-5.268422429466566e+95, -1.4816907071451201e-177)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m12_floatX5FmiscX2E0Export7_f64X2Ediv(&instance, 4.03995627001749e+54, -4.7097881971884274e+64)),
        13679565210380085385ull,
        "f64.div(4.03995627001749e+54, -4.7097881971884274e+64)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m12_floatX5FmiscX2E0Export7_f64X2Ediv(&instance, -2.039595604683476e+176, -7.474088739461226e+58)),
        6363956244686200611ull,
        "f64.div(-2.039595604683476e+176, -7.474088739461226e+58)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m12_floatX5FmiscX2E0Export7_f64X2Ediv(&instance, -3.0426171229468766e+164, -2.6556792326588243e+99)),
        5580355845867636249ull,
        "f64.div(-3.0426171229468766e+164, -2.6556792326588243e+99)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m12_floatX5FmiscX2E0Export7_f64X2Ediv(&instance, 4.923524051248073e+55, -3.663408283100367e+290)),
        10316437533262127859ull,
        "f64.div(4.923524051248073e+55, -3.663408283100367e+290)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m12_floatX5FmiscX2E0Export7_f64X2Ediv(&instance, 2.892608435563416e+65, 5.171948758373355e+128)),
        3660708720660625999ull,
        "f64.div(2.892608435563416e+65, 5.171948758373355e+128)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m12_floatX5FmiscX2E0Export7_f64X2Ediv(&instance, -4.215425823442686e+248, 1.4285058546706491e+105)),
        15976575755200563719ull,
        "f64.div(-4.215425823442686e+248, 1.4285058546706491e+105)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m12_floatX5FmiscX2E0Export7_f64X2Ediv(&instance, 1.8622957433108482, 1.7976931348623157e+308)),
        2096758603907099ull,
        "f64.div(1.8622957433108482, 1.7976931348623157e+308)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m12_floatX5FmiscX2E0Export7_f64X2Ediv(&instance, 8.566632480779937e-305, 5381.2699796556235)),
        3222112482593593ull,
        "f64.div(8.566632480779937e-305, 5381.2699796556235)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m12_floatX5FmiscX2E0Export7_f64X2Ediv(&instance, -8.196220919495565e-44, -1.0406557086484777e+265)),
        1594123367530375ull,
        "f64.div(-8.196220919495565e-44, -1.0406557086484777e+265)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m12_floatX5FmiscX2E0Export7_f64X2Ediv(&instance, -7.052801866447111e-119, -1.3767429405781133e+190)),
        1036869663772871ull,
        "f64.div(-7.052801866447111e-119, -1.3767429405781133e+190)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m12_floatX5FmiscX2E0Export7_f64X2Ediv(&instance, 2.2655621734165475e-258, 1.332199329634947e+50)),
        3442089173194313ull,
        "f64.div(2.2655621734165475e-258, 1.332199329634947e+50)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m12_floatX5FmiscX2E0Export7_f64X2Ediv(&instance, 4.196304106554003e-303, -9789327.297653636)),
        9223458798833500621ull,
        "f64.div(4.196304106554003e-303, -9789327.297653636)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m12_floatX5FmiscX2E0Export7_f32X2Ediv(&instance, 1.0388607849935468e+27, 6211079503872.0)),
        1461198615u,
        "f32.div(1.0388607849935468e+27, 6211079503872.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m12_floatX5FmiscX2E0Export7_f32X2Ediv(&instance, 1.8690329639854072e+27, -1.1235572810773782e+32)),
        3079375694u,
        "f32.div(1.8690329639854072e+27, -1.1235572810773782e+32)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m12_floatX5FmiscX2E0Export7_f32X2Ediv(&instance, 3.290747245341552e+24, 0.9064788222312927)),
        1749036825u,
        "f32.div(3.290747245341552e+24, 0.9064788222312927)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m12_floatX5FmiscX2E0Export7_f32X2Ediv(&instance, -908946.5625, -17034289152.0)),
        945802923u,
        "f32.div(-908946.5625, -17034289152.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m12_floatX5FmiscX2E0Export7_f32X2Ediv(&instance, -2.409247660314223e-13, -8.984081163773542e+16)),
        240750700u,
        "f32.div(-2.409247660314223e-13, -8.984081163773542e+16)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m12_floatX5FmiscX2E0Export7_f64X2Ediv(&instance, 3.910973045785834e+18, -8.392730733897136e-260)),
        17984289216286432053ull,
        "f64.div(3.910973045785834e+18, -8.392730733897136e-260)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m12_floatX5FmiscX2E0Export7_f64X2Ediv(&instance, 8.379351966732404e-40, -2.1077277802048832e-157)),
        15589554694846453438ull,
        "f64.div(8.379351966732404e-40, -2.1077277802048832e-157)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m12_floatX5FmiscX2E0Export7_f64X2Ediv(&instance, 4.561142017854715e+201, 1.5005780677368491e+192)),
        4748664889769504925ull,
        "f64.div(4.561142017854715e+201, 1.5005780677368491e+192)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m12_floatX5FmiscX2E0Export7_f64X2Ediv(&instance, -6.236072401827852e+54, 8.31706325046099e+232)),
        11165393291297270552ull,
        "f64.div(-6.236072401827852e+54, 8.31706325046099e+232)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m12_floatX5FmiscX2E0Export7_f64X2Ediv(&instance, -9.757271330468098e-263, -3.5613812243480865e-195)),
        3596021921286071170ull,
        "f64.div(-9.757271330468098e-263, -3.5613812243480865e-195)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m12_floatX5FmiscX2E0Export7_f64X2Ediv(&instance, 1.046256872449641e-17, 1.8150892711657447)),
        4348952422448611708ull,
        "f64.div(1.046256872449641e-17, 1.8150892711657447)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m12_floatX5FmiscX2E0Export7_f64X2Ediv(&instance, 2.2038268106596436e-31, -2.859803943943555e-13)),
        13559333871418047670ull,
        "f64.div(2.2038268106596436e-31, -2.859803943943555e-13)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m12_floatX5FmiscX2E0Export7_f64X2Ediv(&instance, 7.596539988437179e-13, 2.1055358831337124e-34)),
        4929315895081747238ull,
        "f64.div(7.596539988437179e-13, 2.1055358831337124e-34)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m12_floatX5FmiscX2E0Export7_f64X2Ediv(&instance, 1.1206961145008669e+27, 1.597132338028665e+29)),
        4574739988274663188ull,
        "f64.div(1.1206961145008669e+27, 1.597132338028665e+29)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m12_floatX5FmiscX2E0Export7_f64X2Ediv(&instance, 0.0006342142502301953, -6391950865520085.0)),
        13546063418479940250ull,
        "f64.div(0.0006342142502301953, -6391950865520085.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m12_floatX5FmiscX2E0Export7_f32X2Ediv(&instance, 1.1754943508222875e-38, 1.1754942106924411e-38)),
        1065353217u,
        "f32.div(1.1754943508222875e-38, 1.1754942106924411e-38)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m12_floatX5FmiscX2E0Export7_f32X2Ediv(&instance, 1.1754942106924411e-38, 1.1754943508222875e-38)),
        1065353214u,
        "f32.div(1.1754942106924411e-38, 1.1754943508222875e-38)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m12_floatX5FmiscX2E0Export7_f64X2Ediv(&instance, 2.2250738585072014e-308, 2.225073858507201e-308)),
        4607182418800017409ull,
        "f64.div(2.2250738585072014e-308, 2.225073858507201e-308)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m12_floatX5FmiscX2E0Export7_f64X2Ediv(&instance, 2.225073858507201e-308, 2.2250738585072014e-308)),
        4607182418800017406ull,
        "f64.div(2.225073858507201e-308, 2.2250738585072014e-308)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m12_floatX5FmiscX2E0Export7_f32X2Ediv(&instance, 2.3841856489070778e-07, 3.4028234663852886e+38)),
        0u,
        "f32.div(2.3841856489070778e-07, 3.4028234663852886e+38)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m12_floatX5FmiscX2E0Export7_f32X2Ediv(&instance, 2.384185791015625e-07, 3.4028234663852886e+38)),
        1u,
        "f32.div(2.384185791015625e-07, 3.4028234663852886e+38)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m12_floatX5FmiscX2E0Export7_f64X2Ediv(&instance, 4.4408920985006257e-16, 1.7976931348623157e+308)),
        0ull,
        "f64.div(4.4408920985006257e-16, 1.7976931348623157e+308)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m12_floatX5FmiscX2E0Export7_f64X2Ediv(&instance, 4.440892098500626e-16, 1.7976931348623157e+308)),
        1ull,
        "f64.div(4.440892098500626e-16, 1.7976931348623157e+308)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m12_floatX5FmiscX2E0Export7_f32X2Ediv(&instance, 1.0, 2.938735877055719e-39)),
        2139095040u,
        "f32.div(1.0, 2.938735877055719e-39)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m12_floatX5FmiscX2E0Export7_f32X2Ediv(&instance, 1.0, 2.938737278354183e-39)),
        2139095032u,
        "f32.div(1.0, 2.938737278354183e-39)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m12_floatX5FmiscX2E0Export7_f64X2Ediv(&instance, 1.0, 5.562684646268003e-309)),
        9218868437227405312ull,
        "f64.div(1.0, 5.562684646268003e-309)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m12_floatX5FmiscX2E0Export7_f64X2Ediv(&instance, 1.0, 5.56268464626801e-309)),
        9218868437227405304ull,
        "f64.div(1.0, 5.56268464626801e-309)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m12_floatX5FmiscX2E0Export7_f32X2Ediv(&instance, 1.0, 8.507060187143942e+37)),
        8388607u,
        "f32.div(1.0, 8.507060187143942e+37)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m12_floatX5FmiscX2E0Export7_f32X2Ediv(&instance, 1.0, 8.507059173023462e+37)),
        8388608u,
        "f32.div(1.0, 8.507059173023462e+37)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m12_floatX5FmiscX2E0Export7_f64X2Ediv(&instance, 1.0, 4.494232837155791e+307)),
        4503599627370495ull,
        "f64.div(1.0, 4.494232837155791e+307)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m12_floatX5FmiscX2E0Export7_f64X2Ediv(&instance, 1.0, 4.49423283715579e+307)),
        4503599627370496ull,
        "f64.div(1.0, 4.49423283715579e+307)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m12_floatX5FmiscX2E0Export7_f32X2Ediv(&instance, 1.0, 3.0)),
        1051372203u,
        "f32.div(1.0, 3.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m12_floatX5FmiscX2E0Export7_f32X2Ediv(&instance, 3.0, 9.0)),
        1051372203u,
        "f32.div(3.0, 9.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m12_floatX5FmiscX2E0Export7_f32X2Ediv(&instance, 9.0, 27.0)),
        1051372203u,
        "f32.div(9.0, 27.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m12_floatX5FmiscX2E0Export7_f64X2Ediv(&instance, 1.0, 3.0)),
        4599676419421066581ull,
        "f64.div(1.0, 3.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m12_floatX5FmiscX2E0Export7_f64X2Ediv(&instance, 3.0, 9.0)),
        4599676419421066581ull,
        "f64.div(3.0, 9.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m12_floatX5FmiscX2E0Export7_f64X2Ediv(&instance, 9.0, 27.0)),
        4599676419421066581ull,
        "f64.div(9.0, 27.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m12_floatX5FmiscX2E0Export7_f32X2Ediv(&instance, 1.0000001192092896, 0.9999999403953552)),
        1065353218u,
        "f32.div(1.0000001192092896, 0.9999999403953552)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m12_floatX5FmiscX2E0Export7_f32X2Ediv(&instance, 0.9999999403953552, 1.0000001192092896)),
        1065353213u,
        "f32.div(0.9999999403953552, 1.0000001192092896)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m12_floatX5FmiscX2E0Export7_f32X2Ediv(&instance, 1.0, 0.9999999403953552)),
        1065353217u,
        "f32.div(1.0, 0.9999999403953552)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m12_floatX5FmiscX2E0Export7_f32X2Ediv(&instance, 1.0, 1.0000001192092896)),
        1065353214u,
        "f32.div(1.0, 1.0000001192092896)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m12_floatX5FmiscX2E0Export7_f64X2Ediv(&instance, 1.0000000000000002, 0.9999999999999999)),
        4607182418800017410ull,
        "f64.div(1.0000000000000002, 0.9999999999999999)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m12_floatX5FmiscX2E0Export7_f64X2Ediv(&instance, 0.9999999999999999, 1.0000000000000002)),
        4607182418800017405ull,
        "f64.div(0.9999999999999999, 1.0000000000000002)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m12_floatX5FmiscX2E0Export7_f64X2Ediv(&instance, 1.0, 0.9999999999999999)),
        4607182418800017409ull,
        "f64.div(1.0, 0.9999999999999999)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m12_floatX5FmiscX2E0Export7_f64X2Ediv(&instance, 1.0, 1.0000000000000002)),
        4607182418800017406ull,
        "f64.div(1.0, 1.0000000000000002)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m12_floatX5FmiscX2E0Export8_f32X2Esqrt(&instance, 171.0)),
        1095842342u,
        "f32.sqrt(171.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m12_floatX5FmiscX2E0Export8_f32X2Esqrt(&instance, 1.607949968729372e-07)),
        970079310u,
        "f32.sqrt(1.607949968729372e-07)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m12_floatX5FmiscX2E0Export8_f64X2Esqrt(&instance, 171.0)),
        4623551143926461685ull,
        "f64.sqrt(171.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m12_floatX5FmiscX2E0Export8_f64X2Esqrt(&instance, 1.60795e-07)),
        4556032630010904473ull,
        "f64.sqrt(1.60795e-07)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m12_floatX5FmiscX2E0Export8_f64X2Esqrt(&instance, 4.316357580352844e-50)),
        4237908228221851551ull,
        "f64.sqrt(4.316357580352844e-50)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m12_floatX5FmiscX2E0Export8_f64X2Esqrt(&instance, 6.762533004796485e+101)),
        5368736472460186647ull,
        "f64.sqrt(6.762533004796485e+101)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m12_floatX5FmiscX2E0Export8_f64X2Esqrt(&instance, 1.7485296624861996e+121)),
        5513761933181195411ull,
        "f64.sqrt(1.7485296624861996e+121)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m12_floatX5FmiscX2E0Export8_f64X2Esqrt(&instance, 9.593720960603523e-12)),
        4524423892028972029ull,
        "f64.sqrt(9.593720960603523e-12)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m12_floatX5FmiscX2E0Export8_f64X2Esqrt(&instance, 6.348452898717835e-112)),
        3775077603066051757ull,
        "f64.sqrt(6.348452898717835e-112)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m12_floatX5FmiscX2E0Export8_f64X2Esqrt(&instance, 0.9999999999999999)),
        4607182418800017407ull,
        "f64.sqrt(0.9999999999999999)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m12_floatX5FmiscX2E0Export8_f32X2Esqrt(&instance, 0.1296394169330597)),
        1052268824u,
        "f32.sqrt(0.1296394169330597)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m12_floatX5FmiscX2E0Export8_f32X2Esqrt(&instance, 2.3458758227068622e+30)),
        1487806505u,
        "f32.sqrt(2.3458758227068622e+30)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m12_floatX5FmiscX2E0Export8_f32X2Esqrt(&instance, 0.07878657430410385)),
        1049605767u,
        "f32.sqrt(0.07878657430410385)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m12_floatX5FmiscX2E0Export8_f32X2Esqrt(&instance, 5.137102604477576e-22)),
        768040305u,
        "f32.sqrt(5.137102604477576e-22)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m12_floatX5FmiscX2E0Export8_f32X2Esqrt(&instance, 0.0009016715339384973)),
        1022754037u,
        "f32.sqrt(0.0009016715339384973)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m12_floatX5FmiscX2E0Export8_f64X2Esqrt(&instance, 9.591922760825561e-279)),
        2527268346316778217ull,
        "f64.sqrt(9.591922760825561e-279)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m12_floatX5FmiscX2E0Export8_f64X2Esqrt(&instance, 9.357875352164005e+218)),
        6244818117372907505ull,
        "f64.sqrt(9.357875352164005e+218)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m12_floatX5FmiscX2E0Export8_f64X2Esqrt(&instance, 1.4770669978336558e+116)),
        5476089630784211276ull,
        "f64.sqrt(1.4770669978336558e+116)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m12_floatX5FmiscX2E0Export8_f64X2Esqrt(&instance, 4.880045718002789e+31)),
        4843851732197030563ull,
        "f64.sqrt(4.880045718002789e+31)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m12_floatX5FmiscX2E0Export8_f64X2Esqrt(&instance, 7.61897768717454e+300)),
        6857570252025178944ull,
        "f64.sqrt(7.61897768717454e+300)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m12_floatX5FmiscX2E0Export8_f32X2Esqrt(&instance, 154481008.0)),
        1178743848u,
        "f32.sqrt(154481008.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m12_floatX5FmiscX2E0Export8_f32X2Esqrt(&instance, 1.047130482506864e-34)),
        591184817u,
        "f32.sqrt(1.047130482506864e-34)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m12_floatX5FmiscX2E0Export8_f32X2Esqrt(&instance, 3.790637128986418e-05)),
        1003077404u,
        "f32.sqrt(3.790637128986418e-05)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m12_floatX5FmiscX2E0Export8_f32X2Esqrt(&instance, 8.960753473528173e-37)),
        562803203u,
        "f32.sqrt(8.960753473528173e-37)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m12_floatX5FmiscX2E0Export8_f32X2Esqrt(&instance, 1.6877119874218322e-37)),
        552763653u,
        "f32.sqrt(1.6877119874218322e-37)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m12_floatX5FmiscX2E0Export8_f64X2Esqrt(&instance, 3.169962643789095e+209)),
        6174272493021072850ull,
        "f64.sqrt(3.169962643789095e+209)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m12_floatX5FmiscX2E0Export8_f64X2Esqrt(&instance, 4.0573669271847993e-230)),
        2891239701856850373ull,
        "f64.sqrt(4.0573669271847993e-230)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m12_floatX5FmiscX2E0Export8_f64X2Esqrt(&instance, 1.5299861660588838e-09)),
        4540897185465678583ull,
        "f64.sqrt(1.5299861660588838e-09)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m12_floatX5FmiscX2E0Export8_f64X2Esqrt(&instance, 2.822766928951239e-73)),
        4064104284248214854ull,
        "f64.sqrt(2.822766928951239e-73)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m12_floatX5FmiscX2E0Export8_f64X2Esqrt(&instance, 1.4375957727045067e+280)),
        6702520650372831162ull,
        "f64.sqrt(1.4375957727045067e+280)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m12_floatX5FmiscX2E0Export8_f32X2Esqrt(&instance, 4.6402342298538086e+35)),
        1561805138u,
        "f32.sqrt(4.6402342298538086e+35)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m12_floatX5FmiscX2E0Export8_f32X2Esqrt(&instance, 47536.1328125)),
        1129973536u,
        "f32.sqrt(47536.1328125)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m12_floatX5FmiscX2E0Export8_f32X2Esqrt(&instance, 0.8126130104064941)),
        1063699830u,
        "f32.sqrt(0.8126130104064941)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m12_floatX5FmiscX2E0Export8_f32X2Esqrt(&instance, 9.549604991959535e-27)),
        702287090u,
        "f32.sqrt(9.549604991959535e-27)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m12_floatX5FmiscX2E0Export8_f32X2Esqrt(&instance, 6.885648533602653e-29)),
        672496559u,
        "f32.sqrt(6.885648533602653e-29)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m12_floatX5FmiscX2E0Export8_f64X2Esqrt(&instance, 2.3497689174953322e+222)),
        6270248298536475417ull,
        "f64.sqrt(2.3497689174953322e+222)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m12_floatX5FmiscX2E0Export8_f64X2Esqrt(&instance, 2.9262574743429683e-115)),
        3750137482611732493ull,
        "f64.sqrt(2.9262574743429683e-115)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m12_floatX5FmiscX2E0Export8_f64X2Esqrt(&instance, 3.773350874844908e+290)),
        6780419764181964566ull,
        "f64.sqrt(3.773350874844908e+290)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m12_floatX5FmiscX2E0Export8_f64X2Esqrt(&instance, 3.5498432023945234e-14)),
        4506213966714545194ull,
        "f64.sqrt(3.5498432023945234e-14)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m12_floatX5FmiscX2E0Export8_f64X2Esqrt(&instance, 1.3747419336166767e-148)),
        3500764341454448999ull,
        "f64.sqrt(1.3747419336166767e-148)"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m12_floatX5FmiscX2E0Export8_f64X2Esqrt(&instance, -1.5535152663257847e-290)) & 9223372036854775807ull),
        9221120237041090560ull,
        "f64.sqrt(-1.5535152663257847e-290)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m12_floatX5FmiscX2E0Export8_f64X2Esqrt(&instance, 1.87632963480297e+31)),
        4841025724322244342ull,
        "f64.sqrt(1.87632963480297e+31)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m12_floatX5FmiscX2E0Export8_f64X2Esqrt(&instance, 2.74405777036165e-229)),
        2897120674751402313ull,
        "f64.sqrt(2.74405777036165e-229)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m12_floatX5FmiscX2E0Export8_f64X2Esqrt(&instance, 1.5613859952920445e-83)),
        3987382964717611901ull,
        "f64.sqrt(1.5613859952920445e-83)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m12_floatX5FmiscX2E0Export8_f64X2Esqrt(&instance, 6.193037689450712e+170)),
        5884408968142469554ull,
        "f64.sqrt(6.193037689450712e+170)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m12_floatX5FmiscX2E0Export8_f32X2Esqrt(&instance, 1.0000001192092896)),
        1065353216u,
        "f32.sqrt(1.0000001192092896)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m12_floatX5FmiscX2E0Export8_f32X2Esqrt(&instance, 1.000000238418579)),
        1065353217u,
        "f32.sqrt(1.000000238418579)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m12_floatX5FmiscX2E0Export8_f64X2Esqrt(&instance, 1.0000000000000002)),
        4607182418800017408ull,
        "f64.sqrt(1.0000000000000002)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m12_floatX5FmiscX2E0Export8_f64X2Esqrt(&instance, 1.0000000000000004)),
        4607182418800017409ull,
        "f64.sqrt(1.0000000000000004)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m12_floatX5FmiscX2E0Export8_f32X2Esqrt(&instance, 0.9999998807907104)),
        1065353215u,
        "f32.sqrt(0.9999998807907104)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m12_floatX5FmiscX2E0Export8_f32X2Esqrt(&instance, 0.9999998211860657)),
        1065353214u,
        "f32.sqrt(0.9999998211860657)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m12_floatX5FmiscX2E0Export8_f64X2Esqrt(&instance, 0.9999999999999998)),
        4607182418800017407ull,
        "f64.sqrt(0.9999999999999998)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m12_floatX5FmiscX2E0Export8_f64X2Esqrt(&instance, 0.9999999999999997)),
        4607182418800017406ull,
        "f64.sqrt(0.9999999999999997)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m12_floatX5FmiscX2E0Export8_f32X2Esqrt(&instance, 0.2499999850988388)),
        1056964607u,
        "f32.sqrt(0.2499999850988388)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m12_floatX5FmiscX2E0Export8_f32X2Esqrt(&instance, 0.25)),
        1056964608u,
        "f32.sqrt(0.25)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m12_floatX5FmiscX2E0Export8_f32X2Esqrt(&instance, 0.2500000298023224)),
        1056964608u,
        "f32.sqrt(0.2500000298023224)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m12_floatX5FmiscX2E0Export8_f32X2Esqrt(&instance, 0.2500000596046448)),
        1056964609u,
        "f32.sqrt(0.2500000596046448)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m12_floatX5FmiscX2E0Export8_f64X2Esqrt(&instance, 0.24999999999999997)),
        4602678819172646911ull,
        "f64.sqrt(0.24999999999999997)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m12_floatX5FmiscX2E0Export8_f64X2Esqrt(&instance, 0.25)),
        4602678819172646912ull,
        "f64.sqrt(0.25)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m12_floatX5FmiscX2E0Export8_f64X2Esqrt(&instance, 0.25000000000000006)),
        4602678819172646912ull,
        "f64.sqrt(0.25000000000000006)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m12_floatX5FmiscX2E0Export8_f64X2Esqrt(&instance, 0.2500000000000001)),
        4602678819172646913ull,
        "f64.sqrt(0.2500000000000001)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m12_floatX5FmiscX2E0Export8_f32X2Esqrt(&instance, 272331603968.0)),
        1224658880u,
        "f32.sqrt(272331603968.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m12_floatX5FmiscX2E0Export8_f64X2Esqrt(&instance, 272331606109.83676)),
        4692708996063213197ull,
        "f64.sqrt(272331606109.83676)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m12_floatX5FmiscX2E0Export8_f32X2Esqrt(&instance, 10616005632.0)),
        1204370688u,
        "f32.sqrt(10616005632.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m12_floatX5FmiscX2E0Export8_f32X2Esqrt(&instance, 3014768273129472.0)),
        1280406534u,
        "f32.sqrt(3014768273129472.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m12_floatX5FmiscX2E0Export8_f32X2Esqrt(&instance, 24597323841536.0)),
        1251433122u,
        "f32.sqrt(24597323841536.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m12_floatX5FmiscX2E0Export8_f32X2Esqrt(&instance, 1234567936.0)),
        1191788651u,
        "f32.sqrt(1234567936.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m12_floatX5FmiscX2E0Export8_f64X2Esqrt(&instance, 10616005156.0)),
        4681816855776591872ull,
        "f64.sqrt(10616005156.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m12_floatX5FmiscX2E0Export8_f64X2Esqrt(&instance, 3014768326492836.0)),
        4722638290031738880ull,
        "f64.sqrt(3014768326492836.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m12_floatX5FmiscX2E0Export8_f64X2Esqrt(&instance, 24597324665761.0)),
        4707083307639111680ull,
        "f64.sqrt(24597324665761.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m12_floatX5FmiscX2E0Export8_f64X2Esqrt(&instance, 1234567891.0)),
        4675061926143203535ull,
        "f64.sqrt(1234567891.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m12_floatX5FmiscX2E0Export8_f32X2Esqrt(&instance, 0.5158079862594604)),
        1060625359u,
        "f32.sqrt(0.5158079862594604)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m12_floatX5FmiscX2E0Export8_f32X2Esqrt(&instance, 0.5028960704803467)),
        1060473591u,
        "f32.sqrt(0.5028960704803467)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m12_floatX5FmiscX2E0Export8_f64X2Esqrt(&instance, 0.5158079862594604)),
        4604644169646845946ull,
        "f64.sqrt(0.5158079862594604)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m12_floatX5FmiscX2E0Export8_f64X2Esqrt(&instance, 0.5028960704803467)),
        4604562689808079765ull,
        "f64.sqrt(0.5028960704803467)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m12_floatX5FmiscX2E0Export8_f32X2Esqrt(&instance, 9.0)),
        1077936128u,
        "f32.sqrt(9.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m12_floatX5FmiscX2E0Export8_f32X2Esqrt(&instance, 137.0)),
        1094403699u,
        "f32.sqrt(137.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m12_floatX5FmiscX2E0Export8_f32X2Esqrt(&instance, 1.7737711668014526)),
        1068136808u,
        "f32.sqrt(1.7737711668014526)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m12_floatX5FmiscX2E0Export8_f32X2Esqrt(&instance, 1000.0)),
        1107098482u,
        "f32.sqrt(1000.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m12_floatX5FmiscX2E0Export8_f64X2Esqrt(&instance, 9.0)),
        4613937818241073152ull,
        "f64.sqrt(9.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m12_floatX5FmiscX2E0Export8_f64X2Esqrt(&instance, 137.0)),
        4622778778324308448ull,
        "f64.sqrt(137.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m12_floatX5FmiscX2E0Export8_f64X2Esqrt(&instance, 1.7737712281864233)),
        4608676848398421769ull,
        "f64.sqrt(1.7737712281864233)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m12_floatX5FmiscX2E0Export8_f64X2Esqrt(&instance, 1000.0)),
        4629594237989614119ull,
        "f64.sqrt(1000.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m12_floatX5FmiscX2E0Export7_f32X2Eabs(&instance, f32_reinterpret_i32(0x7f80f1e2u))),
        2139156962u,
        "f32.abs(f32_reinterpret_i32(0x7f80f1e2u))"
    );
    assertEqualU32(
        i32_reinterpret_f32(m12_floatX5FmiscX2E0Export7_f32X2Eabs(&instance, f32_reinterpret_i32(0xff80f1e2u))),
        2139156962u,
        "f32.abs(f32_reinterpret_i32(0xff80f1e2u))"
    );
    assertEqualU64(
        i64_reinterpret_f64(m12_floatX5FmiscX2E0Export7_f64X2Eabs(&instance, f64_reinterpret_i64(0x7ff00000f1e27a6bull))),
        9218868441285556843ull,
        "f64.abs(f64_reinterpret_i64(0x7ff00000f1e27a6bull))"
    );
    assertEqualU64(
        i64_reinterpret_f64(m12_floatX5FmiscX2E0Export7_f64X2Eabs(&instance, f64_reinterpret_i64(0xfff00000f1e27a6bull))),
        9218868441285556843ull,
        "f64.abs(f64_reinterpret_i64(0xfff00000f1e27a6bull))"
    );
    assertEqualU32(
        i32_reinterpret_f32(m12_floatX5FmiscX2E0Export7_f32X2Eneg(&instance, f32_reinterpret_i32(0x7f80f1e2u))),
        4286640610u,
        "f32.neg(f32_reinterpret_i32(0x7f80f1e2u))"
    );
    assertEqualU32(
        i32_reinterpret_f32(m12_floatX5FmiscX2E0Export7_f32X2Eneg(&instance, f32_reinterpret_i32(0xff80f1e2u))),
        2139156962u,
        "f32.neg(f32_reinterpret_i32(0xff80f1e2u))"
    );
    assertEqualU64(
        i64_reinterpret_f64(m12_floatX5FmiscX2E0Export7_f64X2Eneg(&instance, f64_reinterpret_i64(0x7ff00000f1e27a6bull))),
        18442240478140332651ull,
        "f64.neg(f64_reinterpret_i64(0x7ff00000f1e27a6bull))"
    );
    assertEqualU64(
        i64_reinterpret_f64(m12_floatX5FmiscX2E0Export7_f64X2Eneg(&instance, f64_reinterpret_i64(0xfff00000f1e27a6bull))),
        9218868441285556843ull,
        "f64.neg(f64_reinterpret_i64(0xfff00000f1e27a6bull))"
    );
    assertEqualU32(
        i32_reinterpret_f32(m12_floatX5FmiscX2E0Export12_f32X2Ecopysign(&instance, f32_reinterpret_i32(0x7f80f1e2u), f32_reinterpret_i32(0x7fc00000u))),
        2139156962u,
        "f32.copysign(f32_reinterpret_i32(0x7f80f1e2u), f32_reinterpret_i32(0x7fc00000u))"
    );
    assertEqualU32(
        i32_reinterpret_f32(m12_floatX5FmiscX2E0Export12_f32X2Ecopysign(&instance, f32_reinterpret_i32(0x7f80f1e2u), f32_reinterpret_i32(0xffc00000u))),
        4286640610u,
        "f32.copysign(f32_reinterpret_i32(0x7f80f1e2u), f32_reinterpret_i32(0xffc00000u))"
    );
    assertEqualU32(
        i32_reinterpret_f32(m12_floatX5FmiscX2E0Export12_f32X2Ecopysign(&instance, f32_reinterpret_i32(0xff80f1e2u), f32_reinterpret_i32(0x7fc00000u))),
        2139156962u,
        "f32.copysign(f32_reinterpret_i32(0xff80f1e2u), f32_reinterpret_i32(0x7fc00000u))"
    );
    assertEqualU32(
        i32_reinterpret_f32(m12_floatX5FmiscX2E0Export12_f32X2Ecopysign(&instance, f32_reinterpret_i32(0xff80f1e2u), f32_reinterpret_i32(0xffc00000u))),
        4286640610u,
        "f32.copysign(f32_reinterpret_i32(0xff80f1e2u), f32_reinterpret_i32(0xffc00000u))"
    );
    assertEqualU64(
        i64_reinterpret_f64(m12_floatX5FmiscX2E0Export12_f64X2Ecopysign(&instance, f64_reinterpret_i64(0x7ff00000f1e27a6bull), f64_reinterpret_i64(0x7ff8000000000000ull))),
        9218868441285556843ull,
        "f64.copysign(f64_reinterpret_i64(0x7ff00000f1e27a6bull), f64_reinterpret_i64(0x7ff8000000000000ull))"
    );
    assertEqualU64(
        i64_reinterpret_f64(m12_floatX5FmiscX2E0Export12_f64X2Ecopysign(&instance, f64_reinterpret_i64(0x7ff00000f1e27a6bull), f64_reinterpret_i64(0xfff8000000000000ull))),
        18442240478140332651ull,
        "f64.copysign(f64_reinterpret_i64(0x7ff00000f1e27a6bull), f64_reinterpret_i64(0xfff8000000000000ull))"
    );
    assertEqualU64(
        i64_reinterpret_f64(m12_floatX5FmiscX2E0Export12_f64X2Ecopysign(&instance, f64_reinterpret_i64(0xfff00000f1e27a6bull), f64_reinterpret_i64(0x7ff8000000000000ull))),
        9218868441285556843ull,
        "f64.copysign(f64_reinterpret_i64(0xfff00000f1e27a6bull), f64_reinterpret_i64(0x7ff8000000000000ull))"
    );
    assertEqualU64(
        i64_reinterpret_f64(m12_floatX5FmiscX2E0Export12_f64X2Ecopysign(&instance, f64_reinterpret_i64(0xfff00000f1e27a6bull), f64_reinterpret_i64(0xfff8000000000000ull))),
        18442240478140332651ull,
        "f64.copysign(f64_reinterpret_i64(0xfff00000f1e27a6bull), f64_reinterpret_i64(0xfff8000000000000ull))"
    );
    assertEqualU32(
        i32_reinterpret_f32(m12_floatX5FmiscX2E0Export8_f32X2Eceil(&instance, 0.9999999403953552)),
        1065353216u,
        "f32.ceil(0.9999999403953552)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m12_floatX5FmiscX2E0Export8_f32X2Eceil(&instance, 1.0000001192092896)),
        1073741824u,
        "f32.ceil(1.0000001192092896)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m12_floatX5FmiscX2E0Export8_f64X2Eceil(&instance, 0.9999999999999999)),
        4607182418800017408ull,
        "f64.ceil(0.9999999999999999)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m12_floatX5FmiscX2E0Export8_f64X2Eceil(&instance, 1.0000000000000002)),
        4611686018427387904ull,
        "f64.ceil(1.0000000000000002)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m12_floatX5FmiscX2E0Export8_f32X2Eceil(&instance, 8388607.5)),
        1258291200u,
        "f32.ceil(8388607.5)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m12_floatX5FmiscX2E0Export8_f32X2Eceil(&instance, -8388607.5)),
        3405774846u,
        "f32.ceil(-8388607.5)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m12_floatX5FmiscX2E0Export8_f64X2Eceil(&instance, 4503599627370495.5)),
        4841369599423283200ull,
        "f64.ceil(4503599627370495.5)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m12_floatX5FmiscX2E0Export8_f64X2Eceil(&instance, -4503599627370495.5)),
        14064741636278059006ull,
        "f64.ceil(-4503599627370495.5)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m12_floatX5FmiscX2E0Export8_f32X2Eceil(&instance, 16777215.0)),
        1266679807u,
        "f32.ceil(16777215.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m12_floatX5FmiscX2E0Export8_f32X2Eceil(&instance, -16777215.0)),
        3414163455u,
        "f32.ceil(-16777215.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m12_floatX5FmiscX2E0Export8_f64X2Eceil(&instance, 9007199254740991.0)),
        4845873199050653695ull,
        "f64.ceil(9007199254740991.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m12_floatX5FmiscX2E0Export8_f64X2Eceil(&instance, -9007199254740991.0)),
        14069245235905429503ull,
        "f64.ceil(-9007199254740991.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m12_floatX5FmiscX2E0Export9_f32X2Efloor(&instance, -0.9999999403953552)),
        3212836864u,
        "f32.floor(-0.9999999403953552)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m12_floatX5FmiscX2E0Export9_f32X2Efloor(&instance, -1.0000001192092896)),
        3221225472u,
        "f32.floor(-1.0000001192092896)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m12_floatX5FmiscX2E0Export9_f64X2Efloor(&instance, -0.9999999999999999)),
        13830554455654793216ull,
        "f64.floor(-0.9999999999999999)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m12_floatX5FmiscX2E0Export9_f64X2Efloor(&instance, -1.0000000000000002)),
        13835058055282163712ull,
        "f64.floor(-1.0000000000000002)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m12_floatX5FmiscX2E0Export9_f32X2Efloor(&instance, -8388607.5)),
        3405774848u,
        "f32.floor(-8388607.5)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m12_floatX5FmiscX2E0Export9_f32X2Efloor(&instance, 8388607.5)),
        1258291198u,
        "f32.floor(8388607.5)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m12_floatX5FmiscX2E0Export9_f64X2Efloor(&instance, -4503599627370495.5)),
        14064741636278059008ull,
        "f64.floor(-4503599627370495.5)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m12_floatX5FmiscX2E0Export9_f64X2Efloor(&instance, 4503599627370495.5)),
        4841369599423283198ull,
        "f64.floor(4503599627370495.5)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m12_floatX5FmiscX2E0Export9_f32X2Efloor(&instance, 88607.0)),
        1202524032u,
        "f32.floor(88607.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m12_floatX5FmiscX2E0Export9_f64X2Efloor(&instance, 88607.0)),
        4680825439885721600ull,
        "f64.floor(88607.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m12_floatX5FmiscX2E0Export9_f32X2Etrunc(&instance, -8388607.5)),
        3405774846u,
        "f32.trunc(-8388607.5)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m12_floatX5FmiscX2E0Export9_f32X2Etrunc(&instance, 8388607.5)),
        1258291198u,
        "f32.trunc(8388607.5)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m12_floatX5FmiscX2E0Export9_f64X2Etrunc(&instance, -4503599627370495.5)),
        14064741636278059006ull,
        "f64.trunc(-4503599627370495.5)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m12_floatX5FmiscX2E0Export9_f64X2Etrunc(&instance, 4503599627370495.5)),
        4841369599423283198ull,
        "f64.trunc(4503599627370495.5)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m12_floatX5FmiscX2E0Export11_f32X2Enearest(&instance, 8388609.0)),
        1258291201u,
        "f32.nearest(8388609.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m12_floatX5FmiscX2E0Export11_f32X2Enearest(&instance, 8388610.0)),
        1258291202u,
        "f32.nearest(8388610.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m12_floatX5FmiscX2E0Export11_f32X2Enearest(&instance, 0.4999999701976776)),
        0u,
        "f32.nearest(0.4999999701976776)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m12_floatX5FmiscX2E0Export11_f32X2Enearest(&instance, 281474959933440.0)),
        1468006399u,
        "f32.nearest(281474959933440.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m12_floatX5FmiscX2E0Export11_f64X2Enearest(&instance, 4503599627370497.0)),
        4841369599423283201ull,
        "f64.nearest(4503599627370497.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m12_floatX5FmiscX2E0Export11_f64X2Enearest(&instance, 4503599627370498.0)),
        4841369599423283202ull,
        "f64.nearest(4503599627370498.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m12_floatX5FmiscX2E0Export11_f64X2Enearest(&instance, 0.49999999999999994)),
        0ull,
        "f64.nearest(0.49999999999999994)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m12_floatX5FmiscX2E0Export11_f64X2Enearest(&instance, 8.112963841460667e+31)),
        5084563979301289983ull,
        "f64.nearest(8.112963841460667e+31)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m12_floatX5FmiscX2E0Export11_f32X2Enearest(&instance, 4.5)),
        1082130432u,
        "f32.nearest(4.5)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m12_floatX5FmiscX2E0Export11_f32X2Enearest(&instance, -4.5)),
        3229614080u,
        "f32.nearest(-4.5)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m12_floatX5FmiscX2E0Export11_f32X2Enearest(&instance, -3.5)),
        3229614080u,
        "f32.nearest(-3.5)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m12_floatX5FmiscX2E0Export11_f64X2Enearest(&instance, 4.5)),
        4616189618054758400ull,
        "f64.nearest(4.5)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m12_floatX5FmiscX2E0Export11_f64X2Enearest(&instance, -4.5)),
        13839561654909534208ull,
        "f64.nearest(-4.5)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m12_floatX5FmiscX2E0Export11_f64X2Enearest(&instance, -3.5)),
        13839561654909534208ull,
        "f64.nearest(-3.5)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m12_floatX5FmiscX2E0Export11_f32X2Enearest(&instance, -8388607.5)),
        3405774848u,
        "f32.nearest(-8388607.5)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m12_floatX5FmiscX2E0Export11_f32X2Enearest(&instance, 8388607.5)),
        1258291200u,
        "f32.nearest(8388607.5)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m12_floatX5FmiscX2E0Export11_f64X2Enearest(&instance, -4503599627370495.5)),
        14064741636278059008ull,
        "f64.nearest(-4503599627370495.5)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m12_floatX5FmiscX2E0Export11_f64X2Enearest(&instance, 4503599627370495.5)),
        4841369599423283200ull,
        "f64.nearest(4503599627370495.5)"
    );
}
