#ifndef PLAYERLOADER_H
#define PLAYERLOADER_H
#include <types.h>
#include <player.h>

typedef struct PlayerLoader {
    Players m_LastLoad;
    EXHashCode m_SoundBank;
} PlayerLoader;

extern PlayerLoader gPlayerLoader;

void PlayerLoader__PreLoad(PlayerLoader* self, Players player);
s32 PlayerLoader__IsLoaded(PlayerLoader* self, Players player);
void PlayerLoader__AcknowledgePreLoad(PlayerLoader* self, Players player);
void PlayerLoader__DeLoad(PlayerLoader* self, Players player);
void PlayerLoader__CanelPreLoad(PlayerLoader* self, Players player);

#endif /* PLAYERLOADER_H */