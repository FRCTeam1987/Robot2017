//
//  TrajectoryRunnerTest.cpp
//  Drive-Path
//
//  Created by Ken Schenke on 1/23/17.
//  Copyright © 2017 Ken Schenke. All rights reserved.
//

#ifdef FOR_TEST

#include "../../../src/Lib/TrajectorStuff/TrajectoryRunner.h"
#include <gtest/gtest.h>

class TrajectoryRunnerTest : public testing::Test
{
    
};

TEST_F(TrajectoryRunnerTest, constructorTest)
{
    std::vector<Trajectory> path;
    TrajectoryRunner runner(path);
    
    ASSERT_EQ(true, runner.IsDone());
}

#endif //End of FOR_TEST
