#ifndef MAINTESTS_H
#define MAINTESTS_H

namespace Tests {
#define RUN_TESTS 0
}

#if RUN_TESTS
#define CATCH_CONFIG_MAIN
#endif
#endif // MAINTESTS_H
