#ifndef GUARD_QUEST_LOG_OBJECTS_H
#define GUARD_QUEST_LOG_OBJECTS_H

#include "global.h"

void __attribute__((long_call)) QL_RecordObjects(struct QuestLogScene *);
void __attribute__((long_call)) QL_LoadObjects(struct QuestLogScene *, struct ObjectEventTemplate *);
void __attribute__((long_call)) QL_TryStopSurfing(void);

#endif //GUARD_QUEST_LOG_OBJECTS_H
