#include "LongNumMod.hpp"
#include <gtest/gtest.h>

class LongNumberModTests : public ::testing::Test {
protected:
    LongNumberMod ln1;
    LongNumberMod ln2;

    LongNumber modulus;

    void SetUp() override {
        ln1 = LongNumber("23a6f9b50d34a7e071ec59f90c123a6f9b50d34a7e071ec59f90c123a6f9b50d34a7e071ec59f90c123a6f9b50d34a7e071ec59f90c1");
        ln2 = LongNumber("d52fdadb34d7e4b85888c9422dd52fdadb34d7e4b85888c9422dd52fdadb34d7e4b85888c9422dd52fdadb34d7e4b85888c9422d");
        modulus = LongNumber("746fc08325b7cb4f4140a64fc439e91d627b30b6bb9df2bfe86624c1029be0478880efc574fac609281697a6cdb6781cc5b13f68");
        ln1.initializeModulus(modulus);
    }
};

TEST_F(LongNumberModTests, AdditionOperatorTest) {
    LongNumberMod ans = ln1 + ln2;
    EXPECT_EQ(ans.getNumHex(), "4695BF5720FAC5CD829490621C9EC7AFAD88A1606D74DC941C3851F90CAF01F729BE721CA8021A45146E1C322E830FFE13DA5E4E");
}

TEST_F(LongNumberModTests, SubtractionOperatorTest) {
    LongNumberMod ans = ln1 - ln2;
    EXPECT_EQ(ans.getNumHex(), "6DF50BAD4E2A2999D685971CD1DC0C6F810BB471EB3B960139753A9D6168196582518020E968D6BF5512C463B5937FC0190CD794");
}

TEST_F(LongNumberModTests, MultiplicationOperatorTest) {
    modulus = LongNumber("746fc08325b7cb4f4140a64fc439e91d627b30b6bb9df2bfe86624c1029be0478880efc574fac609281697a6cdb6781cc5b13f68746fc08325b7cb4f4140a64fc439e91d627b30b6bb9df2bfe86624c1029be0478880efc574fac609281697a6cdb6781cc5b13f68");
    ln1.initializeModulus(modulus);
    LongNumberMod ans = ln1 * ln2;
    EXPECT_EQ(ans.getNumHex(), "617643A20867DD3C0326E928010B93F680947F118A04B85159E4CAF5D2EE5EED7D46AE4D668B5AD72D507AA830175AC98242950E64A0E10117C31B6335AB5C56131AFAFA9865FE20C011B47272614B209D71BC8EC98DA8F102827DFE645764BE938772D30056757D");
}

TEST_F(LongNumberModTests, ToSquareOperatorTest) {
    modulus = LongNumber("06873EE639BBEEB3FE79AAC319CC21F6EB23D0DBF1413FA75F41BE1B997330EE54D9659CC427C676AAA3514FB7789DAD556238C3CB1A04FD59F6623576097991C4F070D9B2EE7ACB8913AF6EF1B094571B354A4159BCFFC420B8BCF7BD1EEDB42B3ADE62D3573C0459EA3");
    ln1.initializeModulus(modulus);
    LongNumberMod ans = ln1.toSquare();
    EXPECT_EQ(ans.getNumHex(), "1A8A95F31DD4AF599CF1D4AECBC222D01C36D510692B7E52BD5EA67B5DCAE842218E6F51F3AED8298D43EF6465A3E50B913B7314DBF6D064AE8F1C701FB926740283E07AC73312B9A785FD2D4D2710173EAB348A4632E3FEB8014DA10734FF546469EDC20C059C766820");
}

TEST_F(LongNumberModTests, PowerOFOperatorTest) {
    modulus = LongNumber("D810E45C9E929E7BE8C3E4A840E8B62FC1BBDA70CDDCC874460C245987DC2613C3B8C487702F6326F99C5B43A9BE8ADD7441AF35E077E29C7E2F49D893A3C1B312917A7921C74B8A3C0381A34DB28E4AEF73E6266D4F2628A894673120F1562BD8CBFB1C55987C00459001B4BE35D741F3AF883B872BB6DEC7AC8A685C92EB421A6DA9DCE3AB906550D2BCC642A2993482E2E7E51F1EA4727EB6EAC9E0145F3C3FF70EACA98CDE0211530A383E4FB4A320AD3AD4F179BCB11E2F3E29DDFE192DD7B5F38EA009F609EB1A97C57F0E3519056C971A4130");
    ln1.initializeModulus(modulus);   
    ln2 = LongNumber("4");
    LongNumberMod ans = ln1.toPowerOf(ln2);
    EXPECT_EQ(ans.getNumHex(), "2D3988D577910980542921BCB15120EFC8851F7EE99A5862FC8DB479EE58269996FCB1F3B226ADC645B322BB83A1FE1C1CEFD3CC4E0EE61B855D3884AC7C2A1690BC38CB0B46082AEEF5C208B6C2B1938F876B21175962098EA15459EC0B316229B26A1960A9BE921E5C4DF6E818ED17827DD8DAE42A718C265569EB3F613B1A1897B5108C11EA10ED8C8D4F2393CB4B77E563209055EDA97B5B3628E388F31B700CFCC36E0564E95884D709DC5B43D7C952F1A4F5FC7D56241065AC48B8BEC94724014334E5A99F53F89C46BD37F65BC72B19484091");
}

TEST_F(LongNumberModTests, DistributivityTestTest) {
    modulus = LongNumber("746fc0832a2a5b7cb4f4140a64fc439e91d627b30b6bb9df2bfe86624c1029be0478880efc574fac609281697a6cdb6781cc5b13f68746fc08325b7cb4f4140a64fc439e91d627b30b6bb9df2bfe86624c1029be0478880efc574fac609281697a6cdb6781cc5b13f68");
    ln1.initializeModulus(modulus);   
    auto ans1 = (ln1 + ln2) * ln1;
    auto ans2 = ln1 * ln1 + ln1 * ln2;
    EXPECT_EQ(ans1, ans2);
}

TEST_F(LongNumberModTests, MultiplicationAndAdditionOperatorTest) {
    modulus = LongNumber("AE51C814084C8F4137B68384C322E5B1D52C024C5DCA668C11ECFCBE64B024ABE63096A7580C6F5FE6D2CEEF02FAA00F1386F89CF");
    ln1.initializeModulus(modulus);   
    auto ans1 = ln1;
    int i = 200;
    while(i) {
        ans1 = ans1 + ln1;
        i--;
    }

    LongNumber count("C9");
    LongNumberMod countMod(count);
    auto ans2 = ln1 * count;
    EXPECT_EQ(ans1, ans2);
}

// runs for too much time
// TEST_F(LongNumberModTests, EulersTotientTest) {
//     ln1 = LongNumber("8349C1D0A8B38D63B809DEB8B2A8A3");
//     ln2 = LongNumber("6"); 
//     modulus = LongNumber("7");
//     ln1.initializeModulus(modulus); 

//     auto ans1 = ln1.toPowerOf(ln2);
//     LongNumber one("1");
//     LongNumberMod oneMod(one);
//     EXPECT_EQ(ans1, oneMod);

// }