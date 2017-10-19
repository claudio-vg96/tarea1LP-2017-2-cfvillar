#ifndef GENETIC_BEHAVIOUR_H
#define GENETIC_BEHAVIOUR_H

typedef void(*genetic_behaviour_t)(char, int*);

/*
 * This interface must be implemented for each dynamic
 * library that serves as genetic beahaviour meeting the
 * requiremnts set in homework's instructions.
 */
void genetic_behaviour(char event, int* movement);

#endif
