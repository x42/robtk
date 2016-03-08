#ifdef WITH_SIGNATURE // gpg sign tested releases
#include "gp3.h"
#include <sys/types.h>
#include <sys/stat.h>

/* test if file exists and is a regular file - returns 1 if ok */
static int testfile (const char *filename) {
	struct stat s;
	if (!filename || strlen(filename) < 1) return 0;
	int result= stat(filename, &s);
	if (result != 0) return 0; /* stat() failed */
	if (S_ISREG(s.st_mode)) return 1; /* is a regular file - ok */
	return 0;
}

struct license_info {
	char name[64];
	char store[128];
};

typedef struct _LV2_License_Interface {
	int   (*is_licensed)(LV2_Handle instance);
	char* (*licensee)(LV2_Handle instance);
	const char* (*product_uri)(LV2_Handle instance);
	const char* (*product_name)(LV2_Handle instance);
	const char* (*store_url)(LV2_Handle instance);
} LV2_License_Interface;
#endif
