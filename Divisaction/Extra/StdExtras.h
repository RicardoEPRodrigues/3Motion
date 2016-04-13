/*
 * File StdExtras.h in project Divisaction
 * 
 * Copyright (C) ricardo 2016 - All Rights Reserved
 */

#ifndef UTILS_STDEXTRAS_H_
#define UTILS_STDEXTRAS_H_

namespace std {

    /**
     * This struct is used as a middle man in std functions as vector<class*>::find_if()
     * @code
     * Task* Task::getChild(Task* child) const {
     *     pointer_values_equal<Task> eq = { child };
     *     vector<Task*>::iterator findId = find_if(children->begin(), children->end(), eq);
     *     return findId == children->end() ? nullptr : *findId;
     * }
     * @endcode
     */
    template<typename T>
    struct pointer_values_equal {
        const T* to_find;

        bool operator()(const T* other) const;
    };

}

#endif /* UTILS_STDEXTRAS_H_ */
