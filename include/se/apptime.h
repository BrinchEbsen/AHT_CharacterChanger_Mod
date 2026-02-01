#ifndef APPTIME_H
#define APPTIME_H
#include <types.h>

typedef struct XAppTime {
    s16 m_Year; /* Inherited from EXAppTime */
    s8 m_Month; /* Inherited from EXAppTime */
    s8 m_Day; /* Inherited from EXAppTime */
    s8 m_Hours; /* Inherited from EXAppTime */
    s8 m_Minutes; /* Inherited from EXAppTime */
    s8 m_Seconds; /* Inherited from EXAppTime */
} XAppTime;

#endif /* APPTIME_H */