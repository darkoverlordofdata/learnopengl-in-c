#pragma once
#include "unit.h"
#include "test_bitset.h"
#include "test_random.h"
#include "test_uuid.h"

static inline void run_tests()
{
    test_bitset();    
    test_random();    
    test_uuid();    
}