#include <sys/stat.h>
#include <unistd.h>

#include <io500-phase.h>

typedef struct{
  char * api;
  bool odirect;
} opt_ior_easy_read;

static opt_ior_easy_read o;

static ini_option_t option[] = {
  {"API", "The API to be used", 0, INI_STRING, "POSIX", & o.api},
  {"posix.odirect", "Use ODirect", 0, INI_BOOL, NULL, & o.odirect},
  {NULL} };

static ini_option_t * get_ini_section(void){
  return option;
}

static void validate(void){

}

u_phase_t p_ior_easy_read = {
  "ior_easy_read",
  get_ini_section,
  validate,
  NULL
};