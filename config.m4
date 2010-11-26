dnl $Id$
dnl config.m4 for extension minhaextensao

dnl Comments in this file start with the string 'dnl'.
dnl Remove where necessary. This file will not work
dnl without editing.

dnl If your extension references something external, use with:

dnl PHP_ARG_WITH(minhaextensao, for minhaextensao support,
dnl Make sure that the comment is aligned:
dnl [  --with-minhaextensao             Include minhaextensao support])

dnl Otherwise use enable:

PHP_ARG_ENABLE(minhaextensao, whether to enable minhaextensao support,
[  --enable-minhaextensao           Enable minhaextensao support])

if test "$PHP_MINHAEXTENSAO" != "no"; then
  dnl Write more examples of tests here...

  dnl # --with-minhaextensao -> check with-path
  dnl SEARCH_PATH="/usr/local /usr"     # you might want to change this
  dnl SEARCH_FOR="/include/minhaextensao.h"  # you most likely want to change this
  dnl if test -r $PHP_MINHAEXTENSAO/$SEARCH_FOR; then # path given as parameter
  dnl   MINHAEXTENSAO_DIR=$PHP_MINHAEXTENSAO
  dnl else # search default path list
  dnl   AC_MSG_CHECKING([for minhaextensao files in default path])
  dnl   for i in $SEARCH_PATH ; do
  dnl     if test -r $i/$SEARCH_FOR; then
  dnl       MINHAEXTENSAO_DIR=$i
  dnl       AC_MSG_RESULT(found in $i)
  dnl     fi
  dnl   done
  dnl fi
  dnl
  dnl if test -z "$MINHAEXTENSAO_DIR"; then
  dnl   AC_MSG_RESULT([not found])
  dnl   AC_MSG_ERROR([Please reinstall the minhaextensao distribution])
  dnl fi

  dnl # --with-minhaextensao -> add include path
  dnl PHP_ADD_INCLUDE($MINHAEXTENSAO_DIR/include)

  dnl # --with-minhaextensao -> check for lib and symbol presence
  dnl LIBNAME=minhaextensao # you may want to change this
  dnl LIBSYMBOL=minhaextensao # you most likely want to change this 

  dnl PHP_CHECK_LIBRARY($LIBNAME,$LIBSYMBOL,
  dnl [
  dnl   PHP_ADD_LIBRARY_WITH_PATH($LIBNAME, $MINHAEXTENSAO_DIR/lib, MINHAEXTENSAO_SHARED_LIBADD)
  dnl   AC_DEFINE(HAVE_MINHAEXTENSAOLIB,1,[ ])
  dnl ],[
  dnl   AC_MSG_ERROR([wrong minhaextensao lib version or lib not found])
  dnl ],[
  dnl   -L$MINHAEXTENSAO_DIR/lib -lm
  dnl ])
  dnl
  dnl PHP_SUBST(MINHAEXTENSAO_SHARED_LIBADD)

  PHP_NEW_EXTENSION(minhaextensao, minhaextensao.c, $ext_shared)
fi
