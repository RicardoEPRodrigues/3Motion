/*
 * File Emotions.h in project Divisaction
 * 
 * Copyright (C) Ricardo Rodrigues 2016 - All Rights Reserved
 */
#ifndef DIVISACTION_EMOTIONS_H
#define DIVISACTION_EMOTIONS_H

#include "../Emotion.h"

namespace Divisaction {

    class Confidence : public Emotion {
        public:
            Confidence();
    };

    class Fear : public Emotion {
        public:
            Fear();
    };

    class Happiness : public Emotion {
        public:
            Happiness();
    };

    class Relief : public Emotion {
        public:
            Relief();
    };

    class Apprehension : public Emotion {
        public:
            Apprehension();
    };

} /* namespace Divisaction */

#endif //DIVISACTION_EMOTIONS_H
