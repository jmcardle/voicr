#include "backend.h"

Backend::Backend(QObject *parent) :
    QObject(parent)
{
    int heap_size = 210000;
    int load_init_files = 1;

    festival_initialize(load_init_files,heap_size);
    festival_eval_command("(voice_en1_mbrola)");
    festival_say_text("When they’re talking about millenials, they really mean the off-spring of white affluent baby boomers and/or descendants. And while this group might be less prosperous than their parents, we should perhaps step back and question whether their parents wealth was ever deserved in the first place.");
    festival_wait_for_spooler();
}
