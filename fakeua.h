#ifndef FAKEUA_H
#define FAKEUA_H

#include <stdint.h>

#define MAX_UA_NUM 50
#define MAX_TEXT_LEN 256

extern const char *start_page;
extern char *dir[2];

typedef enum {
    BROWSER_NONE = -1,   /* sentinel for "unset" */
    BROWSER_CHROME = 0,
    BROWSER_EDGE,
    BROWSER_FIREFOX,
    BROWSER_SAFARI,
    BROWSER_OPERA,
    BROWSER_COUNT
} BrowserId;

typedef struct {
    char buf[MAX_TEXT_LEN]; // including "\0", the last char: `text.buf[text.pos] = '\0';`
    uint8_t pos; // 0 <= pos <256, including the index of "\0", pos == strlen(buf)
} Text;

typedef struct {
    BrowserId id;
    Text item;
} UA; // one BrowserId, one Text

typedef struct {
    BrowserId id;
    Text items[MAX_UA_NUM];
    uint8_t len;
} Browser; // one BrowserId, many Texts

/*
typedef struct {
    BrowserId id;
    Text *items;
    uint8_t len;
    uint8_t cap;
} Browser;
*/

typedef struct {
    Browser *b;
    const char *path;
} Cache;

int fetch_ua(const char *url, UA *ua);
int load_ua(const char *path, UA *ua);
void *dump_a_browser(void *arg); // accomodate multi-thread needs
void dumps(void);
void deletes(void);

#endif // FAKEUA_H
