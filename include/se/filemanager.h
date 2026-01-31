#ifndef FILEMANAGER_H
#define FILEMANAGER_H
#include <types.h>

//temp
typedef int SE_FileManager;

extern SE_FileManager gSEFileManager;

int SE_FileManager__IsGeoLoaded(SE_FileManager* self, EXHashCode* pList);

#endif /* FILEMANAGER_H */