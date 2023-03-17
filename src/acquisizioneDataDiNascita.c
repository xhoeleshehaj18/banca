#include "../headers/creazioneEmail.h"
#include "../headers/acquisizioneDataDiNascita.h"
#include <time.h>

#define C 100

time_t dateToInt(char *ymd) {
  if (ymd == NULL) {
    return (time_t)-1;
  }

  struct tm tm = {0}; 
  int n = 0;
  sscanf(ymd, "%4d-%2d-%2d %n", &tm.tm_year, &tm.tm_mon, &tm.tm_mday, &n);

  if (n == 0 || ymd[n]) {
    return (time_t)-1; 
  }

  tm.tm_year -= 1900;
  tm.tm_mon--;
  tm.tm_isdst = -1; 

  return mktime(&tm);
}