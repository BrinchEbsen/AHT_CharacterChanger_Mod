#include <bouncler.h>
#include <os.h>
#include <hashcodes.h>
#include <exvector.h>
#include <igmath.h>

EXVector scale_low = {
    1.3f,
    0.6f,
    1.3f,
    0.0f
};

EXVector scale_high = {
    0.8f,
    1.1f,
    0.8f,
    0.0f
};

int cycle_timer = 0;
int cycle_length = 15;

void* create_the_thing(EXVector* pos, EXVector* rot)
{
    void* item = XSEItem__CreateObject();
    if (item == NULL) {
        return NULL;
    }

    XSEItemEnv__AddXSEItem(&theItemEnv, item, 0);

    void* geoFile = EXGeoFile__GetGeoFile(HT_File_Spyro);
    if (geoFile == NULL) {
        return NULL;
    }

    void* animator = EXItemAnimator__CreateFrom(geoFile, HT_Animation_SpyroBP);
    if (animator == NULL) {
        return NULL;
    }

    EXItem__AddAnimator(item, animator);

    EXVector* itemPos = OFFSET_PTR(EXVector, item, 0xD0);
    EXVector* itemRot = OFFSET_PTR(EXVector, item, 0xE0);

    EXVector_Copy(itemPos, pos);
    EXVector_Copy(itemRot, rot);

    return item;
}

void change_item_scale(void *item, EXVector *scl)
{
    EXVector* itemScl = OFFSET_PTR(EXVector, item, 0xF0);
    EXVector_Copy(itemScl, scl);

    //Invalidate item matrix so it actually changes
    bool* validMtx = OFFSET_PTR(bool, item, 0x82);
    *validMtx = false;
}

void animate_bouncler(void* item) {
    int timer = cycle_timer % (cycle_length*2);
    if (timer > cycle_length) {
        timer = (cycle_length*2) - timer;
    }

    EXVector scl = {
        cosine_interp(scale_low.x, scale_high.x, timer, cycle_length),
        cosine_interp(scale_low.y, scale_high.y, timer, cycle_length),
        cosine_interp(scale_low.z, scale_high.z, timer, cycle_length),
        0.0f 
    };

    change_item_scale(item, &scl);

    cycle_timer++;
}

float bias(float t, float power) {
    if (t < 0.5f) {
        return 0.5f * powf(2.0f * t, power);
    } else {
        return 1.0f - 0.5f * powf(2.0f * (1.0f - t), power);
    }
}

float cosine_interp(float start, float end, int time, int max_time) {
    if (time > max_time) {
        time = max_time;
    } else if (time < 0) {
        time = 0;
    }

    float timef = (float)time / (float)max_time;

    float t = 0.5f - (0.5f * cosf(M_PI * timef));

    t = bias(t, 2.5f);

    return start + ((end - start) * t);
}