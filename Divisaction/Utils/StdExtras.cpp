/*
 * File StdExtras.cpp in project Divisaction
 * 
 * Copyright (C) ricardo 2016 - All Rights Reserved
 */
#include "StdExtras.h"

namespace std {
    template<typename T>
    bool pointer_values_equal<T>::operator()(const T* other) const {
        return *to_find == *other;
    }
}
