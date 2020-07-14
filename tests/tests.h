#pragma once
#include "unit.h"
#include "test_bitvector.h"
#include "test_random.h"
#include "test_uuid.h"
#include "test_cfw.h"

static inline void run_tests()
{
    test_cfw();    
    test_bitvector();    
    test_random();    
    test_uuid();    
}