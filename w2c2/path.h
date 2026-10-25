#ifndef W2C2_PATH_H
#define W2C2_PATH_H

#ifdef _WIN32
#define PATH_SEPARATOR '\\'
#define PATH_SEPARATOR_STRING "\\"
#else
#define PATH_SEPARATOR '/'
#define PATH_SEPARATOR_STRING "/"
#endif

/* Accept both native and forward separators on Windows. */
#define wasmPathIsSeparator(c) ((c) == PATH_SEPARATOR || (c) == '/')

/* Returns an allocated path, or NULL on allocation failure or size overflow. */
char*
wasmPathJoin(const char* directory, const char* name);

#endif /* W2C2_PATH_H */
