#ifndef __WMOPTION_H
#define __WMOPTION_H

#include <X11/Xproto.h>
#include "upath.h"
#include "yarray.h"
#include "ypointer.h"

struct WindowOption {
    WindowOption(ustring n_class_instance);

    ustring w_class_instance;
    csmart icon;
    unsigned functions, function_mask;
    unsigned decors, decor_mask;
    unsigned options, option_mask;
    int workspace;
    int layer;
    int tray;
    int gflags;
    int gx, gy;
    unsigned gw, gh;
};

class WindowOptions {
public:
    void setWinOption(ustring n_class_instance,
                      const char *opt, const char *arg);

    void mergeWindowOption(WindowOption &cm,
                           ustring a_class_instance,
                           bool remove);

private:
    YObjectArray<WindowOption> fWinOptions;

    bool findOption(ustring a_class_instance, int *index);

    WindowOption *getOption(ustring a_class_instance);

    static void combineOptions(WindowOption &cm, WindowOption &n);
};

extern WindowOptions *defOptions;
extern WindowOptions *hintOptions;

void loadWinOptions(upath optFile);

#endif

// vim: set sw=4 ts=4 et:
