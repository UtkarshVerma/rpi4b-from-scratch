#pragma once

#define ARRAY_SIZE(arr)             (sizeof(arr) / sizeof(arr[0]))
#define MEMBER_SIZE(parent, member) sizeof(((parent*)0)->member)
