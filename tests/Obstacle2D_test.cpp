#include "gtest/gtest.h"
#include "obstacle.h"
#include <sstream>
#include <iostream>
#include <unordered_set>

TEST(Obstacle2D_test, test_construction)
{
  Point2D p1 = { 1.0f, 1.0f };
  Point2D p2 = { 2.0f, 2.0f };
  Obstacle2D o1 = { p1, p2};

  EXPECT_EQ(o1.GetHealth(), ObstacleHealth);
  EXPECT_EQ(o1.x1(), 1.0f);
  EXPECT_EQ(o1.x2(), 2.0f);
  EXPECT_EQ(o1.y1(), 1.0f);
  EXPECT_EQ(o1.y2(), 2.0f);
}

TEST(Obstacle2D_test, test_move)
{
  Point2D p1 = { 1.0f, 1.0f };
  Point2D p2 = { 2.0f, 2.0f };
  Obstacle2D o1 = { p1, p2};

  Obstacle2D o2 = move(o1);
  EXPECT_EQ(o2.x1(), 1.0f);
  EXPECT_EQ(o1.x1(), 0.0f);
}


