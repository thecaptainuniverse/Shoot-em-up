#include "gtest/gtest.h"
#include "ray2d.h"
#include <sstream>
#include <unordered_set>

TEST(test_ray, test_construction)
{
  //Default creation
  Ray2D r1;
  EXPECT_EQ(r1.x0(), 0.0f);
  EXPECT_EQ(r1.y0(), 0.0f);
  EXPECT_EQ(r1.GetDirect(0), 0.0f);
  EXPECT_EQ(r1.GetDirect(1), 0.0f);


  //Create the ray with angle parametrization
  Ray2D r2(1.0f, 2.0f, M_PI/2.0f);
  EXPECT_EQ(r2.x0(), 1.0f);
  EXPECT_EQ(r2.y0(), 2.0f);
  EXPECT_EQ(r2.GetDirect(0), 0.0f);
  EXPECT_EQ(r2.GetDirect(1), 1.0f);

  //Create the ray
  Ray2D r3(1.0f, 2.0f, 4.0f, 6.0f);
  EXPECT_EQ(r3.x0(), 1.0f);
  EXPECT_EQ(r3.y0(), 2.0f);
  EXPECT_EQ(r3.GetDirect(0), 0.6f);
  EXPECT_EQ(r3.GetDirect(1), 0.8f);

  Ray2D r4=r3;
  EXPECT_EQ(r4, r3);
}

TEST(test_ray, test_initializer_list)
{
  Ray2D r5={1.0f, 2.0f, 4.0f, 6.0f};
  EXPECT_EQ(r5.x0(), 1.0f);
  EXPECT_EQ(r5.y0(), 2.0f);
  EXPECT_EQ(r5.GetDirect(0), 0.6f);
  EXPECT_EQ(r5.GetDirect(1), 0.8f);

  Ray2D r6={1.0f, 2.0f, M_PI/2.0f};
  EXPECT_EQ(r6.x0(), 1.0f);
  EXPECT_EQ(r6.y0(), 2.0f);
  EXPECT_EQ(r6.GetDirect(0), 0.0f);
  EXPECT_EQ(r6.GetDirect(1), 1.0f);

  Ray2D r7={1.0f, 2.0f};
  EXPECT_EQ(r7.x0(), 1.0f);
  EXPECT_EQ(r7.y0(), 2.0f);
  EXPECT_EQ(r7.GetDirect(0), 0.0f);
  EXPECT_EQ(r7.GetDirect(1), 0.0f);



}
