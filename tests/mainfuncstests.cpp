#include <gtest/gtest.h>

#include <cscrypto/cscrypto.hpp>

using namespace cscrypto;

class MainFuncsTest : public ::testing::Test {
protected:
    void SetUp() override {
        ASSERT_TRUE(cryptoInit());
        testData_.resize(10);
        fillBufWithRandomBytes(testData_.data(), testData_.size());
    }

Bytes testData_;
};

TEST_F(MainFuncsTest, Hash) {
    auto h = calculateHash(testData_.data(), testData_.size());
    ASSERT_EQ(h, calculateHash(testData_.data(), testData_.size()));
    ASSERT_NE(h, calculateHash(testData_.data(), testData_.size() - 1));
}
