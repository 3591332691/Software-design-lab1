#include <gtest/gtest.h>

// 测试用例示例
TEST(MyTestCase, Test1) {
    EXPECT_EQ(2 + 2, 4);
}

TEST(MyTestCase, Test2) {
    EXPECT_TRUE(true);
}

// 主函数
int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}