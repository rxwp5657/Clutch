#include <gtest/gtest.h>
#include <iostream>
#include <mat4.hpp>
#include <transforms.hpp>

TEST(TransformsTest, IsUniformScaling)
{
    auto u_scale  = clutch::Scale(1.2f, 1.2f, 1.2f);
    auto nu_scale = clutch::Scale(1.2f, 2.2f, 3.2f);

    ASSERT_TRUE(clutch::IsUniformScale(u_scale));
    ASSERT_FALSE(clutch::IsUniformScale(nu_scale));
}