#include <gtest/gtest.h>
#include <iostream>
#include "../include/lookat.hpp"
#include "../include/vec4.hpp"
#include "../include/projections.hpp"
TEST(LookAtTest, CanMakeLookAt)
{
    clutch::Vec4<float> from{1.0f, 3.0f, 2.0f,0.0f};
    clutch::Vec4<float> to{4.0f,-2.0f, 8.0f,  0.0f};
    clutch::Vec4<float> up{1.0f, 1.0f, 0.0f,  0.0f};

    clutch::Mat4<float> result{-0.50709254f, 0.50709254f, 0.67612338f, 0.0f,
                                0.767716f,   0.6060915f,  0.12121832f, 0.0f,
                               -0.35856858f, 0.59761435f,-0.717137f,   0.0f,
                                0.0f, 0.0f, 0.0f, 1.0f};

    auto transform = clutch::LookAt(from,to,up);

    ASSERT_FLOAT_EQ(transform.get(0,0), -0.51449573);
    ASSERT_FLOAT_EQ(transform.get(0,1),  0.51449573);
    ASSERT_FLOAT_EQ(transform.get(0,2),  0.68599439);
    ASSERT_FLOAT_EQ(transform.get(0,3), -2.4009802);
    
    ASSERT_FLOAT_EQ(transform.get(1,0), 0.77892411);
    ASSERT_FLOAT_EQ(transform.get(1,1), 0.61494005f);
    ASSERT_FLOAT_EQ(transform.get(1,2), 0.12298802);
    ASSERT_FLOAT_EQ(transform.get(1,3), -2.8697202);

    ASSERT_FLOAT_EQ(transform.get(2,0), -0.35856858);
    ASSERT_FLOAT_EQ(transform.get(2,1),  0.59761435);
    ASSERT_FLOAT_EQ(transform.get(2,2), -0.717137f);
    ASSERT_FLOAT_EQ(transform.get(2,3), -2.3841858e-07);

    ASSERT_FLOAT_EQ(transform.get(3,0), 0.0f);
    ASSERT_FLOAT_EQ(transform.get(3,1), 0.0f);
    ASSERT_FLOAT_EQ(transform.get(3,2), 0.0f);
    ASSERT_FLOAT_EQ(transform.get(3,3), 1.0f);
}