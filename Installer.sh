#!/usr/bin/env bash

# texstreamer.sh - build, install, uninstall for TexStreamer ROOT library

set -e  # прерывать при ошибках

# ---- конфигурация ----
PROGRAM="TexStreamer.so"
GENERATED_CXX="TexStreamer.cxx"
SOURCES="TexStreamer.cxx TexStreamer.cpp"
HEADERS="TexStreamer.hh TexStreamerDict.h"
DICT_HEADER="TexStreamerDict.h"
ROOTMAP="${PROGRAM%.so}.rootmap"
PCM="${PROGRAM%.so}_rdict.pcm"

# ---- вспомогательные функции ----
info() { echo "[INFO] $*"; }
error() { echo "[ERROR] $*" >&2; exit 1; }

# получаем флаги ROOT через root-config
get_root_flags() {
    CXX=$(root-config --cxx) || error "root-config not found. Is ROOT installed?"
    CXXFLAGS="$(root-config --cflags) -fPIC -g -Wall"
    ROOTLIBS="$(root-config --glibs) -lMathMore"
    SHARED="-shared"
}

# ---- сборка ----
build() {
    info "Building ${PROGRAM}..."
    get_root_flags

    # генерируем словарь с помощью rootcling
    info "Generating dictionary via rootcling..."
    rootcling -f "$GENERATED_CXX" -rml "$PROGRAM" -rmf "$ROOTMAP" $HEADERS

    # компилируем разделяемую библиотеку
    info "Compiling shared library..."
    $CXX $CXXFLAGS $SHARED -o "$PROGRAM" $SOURCES $ROOTLIBS

    info "Build succeeded: $PROGRAM created"
}

# ---- очистка сгенерированных файлов ----
clean() {
    info "Cleaning generated files..."
    rm -f "$PROGRAM" "$ROOTMAP" "$PCM" "$GENERATED_CXX"
    info "Clean finished"
}

# ---- установка (прописывание переменных в .bashrc) ----
install() {
    local install_dir=$(pwd)
    local bashrc="$HOME/.bashrc"
    [[ -f "$bashrc" ]] || touch "$bashrc"

    # резервная копия
    cp "$bashrc" "$bashrc.backup.$(date +%Y%m%d_%H%M%S)" 2>/dev/null || true

    # TEX_STREAMER
    if grep -q "^export TEX_STREAMER=" "$bashrc"; then
        echo "Found previous installation in ~/.bashrc. Please remove it using \"./Installer.sh uninstall\" command, it will work if previous installation was made from current directory. Otherwise, please remove it manually because I have paws :)"
    else
        echo "export TEX_STREAMER=$install_dir" >> "$bashrc"
        echo "export LD_LIBRARY_PATH=\$LD_LIBRARY_PATH:$install_dir" >> "$bashrc"
        echo "export CPATH=\$CPATH:$install_dir" >> "$bashrc"
        info "Installation complete. Run 'source ~/.bashrc' or restart terminal."
    fi
    
}

# ---- удаление настроек из .bashrc ----
uninstall() {
    local install_dir=$(pwd)
    local bashrc="$HOME/.bashrc"
    [[ -f "$bashrc" ]] || { info "$bashrc not found, nothing to uninstall."; return; }

    cp "$bashrc" "$bashrc.backup.$(date +%Y%m%d_%H%M%S)" 2>/dev/null || true

    # удаляем строку TEX_STREAMER с точным путём
    sed -i "\|^export TEX_STREAMER=$install_dir\$|d" "$bashrc"
    sed -i "\|^export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:$install_dir\$|d" "$bashrc"
    sed -i "\|^export CPATH=$CPATH:$install_dir\$|d" "$bashrc"
}

# ---- справка ----
usage() {
    cat <<EOF
Usage: $0 {build|clean|install|uninstall}

Commands:
  build      - compile TexStreamer.so (requires ROOT)
  clean      - remove generated files (.so, .rootmap, .pcm, TexStreamer.cxx)
  install    - add TEX_STREAMER, LD_LIBRARY_PATH and CPATH to ~/.bashrc
  uninstall  - remove those environment settings from ~/.bashrc
EOF
}

# ---- main ----
case "$1" in
    build)    build ;;
    clean)    clean ;;
    install)  install ;;
    uninstall) uninstall ;;
    *)        usage; exit 1 ;;
esac
