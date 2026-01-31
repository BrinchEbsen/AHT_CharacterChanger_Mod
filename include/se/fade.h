#ifndef FADE_H
#define FADE_H
#include <types.h>

typedef struct SEFade {
    float m_FadeAmount;
	float m_FadeSpeed;
	u32 m_FadeClippedCount;
} SEFade;

#endif /* FADE_H */