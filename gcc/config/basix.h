/* This is the Basix GCC config header. */
#undef TARGET_BASIX
#define TARGET_BASIX 1
#undef LIB_SPEC
#define LIB_SPEC "-lc"
#undef STARTFILE_SPEC
#define STARTFILE_SPEC "crt0.o%s crti.o%s crtbegin.o%s"
#undef ENDFILE_SPEC
#define ENDFILE_SPEC "crtend.o%s crtn.o%s"
#undef TARGET_OS_CPP_BUILTINS
#define TARGET_OS_CPP_BUILTINS()      \
  do {                                \
    builtin_define ("__basix__");      \
    builtin_define ("__unix__");      \
    builtin_assert ("system=basix");   \
    builtin_assert ("system=unix");   \
    builtin_assert ("system=posix");   \
  } while(0);
#undef LINK_SPEC
#define LINK_SPEC "-z max-page-size=4096 %{shared:-shared} %{static:-static} %{!shared: %{!static: %{rdynamic:-export-dynamic}}}"
