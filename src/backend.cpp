#include "backend.h"

Backend::Backend(QObject *parent) :
    QObject(parent)
{

    /*
    // Festival text-to-speech test
    int heap_size = 210000;
    int load_init_files = 1;

    festival_initialize(load_init_files,heap_size);
    festival_eval_command("(voice_en1_mbrola)");
    festival_say_text("When they’re talking about millenials, they really mean the off-spring of white affluent baby boomers and/or descendants. And while this group might be less prosperous than their parents, we should perhaps step back and question whether their parents wealth was ever deserved in the first place.");
    festival_wait_for_spooler(); */

    // Sphinx speech recognition test
    ps_decoder_t *ps;
    cmd_ln_t *config;
    FILE *fh;
    char const *hyp, *uttid;
        int16 buf[512];
    int rv;
    int32 score;

    config = cmd_ln_init(NULL, ps_args(), TRUE,
        "-hmm", "/usr/local/share/pocketsphinx/model/hmm/en_US/hub4wsj_sc_8k",
        "-lm", "/usr/local/share/pocketsphinx/model/lm/en/turtle.DMP",
        "-dict", "/usr/local/share/pocketsphinx/model/lm/en/turtle.dic",
        NULL);

    if (config == NULL)
        return;
    ps = ps_init(config);
    if (ps == NULL)
        return;

    fh = fopen("/home/julien/Development/voicr/goforward.raw", "rb");
    if (fh == NULL) {
        perror("Failed to open goforward.raw");
        return;
    }

    rv = ps_decode_raw(ps, fh, "goforward", -1);
    if (rv < 0)
        return;
    hyp = ps_get_hyp(ps, &score, &uttid);
    if (hyp == NULL)
        return;
    printf("Recognized: %s\n", hyp);

        fseek(fh, 0, SEEK_SET);
        rv = ps_start_utt(ps, "goforward");
    if (rv < 0)
        return;

        while (!feof(fh)) {
            size_t nsamp;
            nsamp = fread(buf, 2, 512, fh);
            rv = ps_process_raw(ps, buf, nsamp, FALSE, FALSE);
        }
        rv = ps_end_utt(ps);
    if (rv < 0)
        return;

    hyp = ps_get_hyp(ps, &score, &uttid);
    if (hyp == NULL)
        return;

    printf("Recognized: %s\n", hyp);

    fclose(fh);
        ps_free(ps);
}
