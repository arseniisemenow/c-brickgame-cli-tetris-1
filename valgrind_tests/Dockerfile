FROM quay.io/school21/alpine:3.16

RUN apk --no-cache --upgrade add \
    git \
    git-lfs \
    curl \
    jq \
    bash \
    build-base \
    python3 \
    valgrind \
    cppcheck \
    alpine-sdk \
    pcre-dev \
    clang-extra-tools \
    build-base \
    check-dev \
    ncurses-dev

COPY . /project

WORKDIR "/project"

ENTRYPOINT ["/bin/bash","tests/valgrind.sh"]
#ENTRYPOINT ["/bin/bash", "-c", "tail -f /dev/null"] // if you want to keep session alive