/*
  +----------------------------------------------------------------------+
  | PHP Version 5                                                        |
  +----------------------------------------------------------------------+
  | Copyright (c) 1997-2010 The PHP Group                                |
  +----------------------------------------------------------------------+
  | This source file is subject to version 3.01 of the PHP license,      |
  | that is bundled with this package in the file LICENSE, and is        |
  | available through the world-wide-web at the following url:           |
  | http://www.php.net/license/3_01.txt                                  |
  | If you did not receive a copy of the PHP license and are unable to   |
  | obtain it through the world-wide-web, please send a note to          |
  | license@php.net so we can mail you a copy immediately.               |
  +----------------------------------------------------------------------+
  | Author:                                                              |
  +----------------------------------------------------------------------+
*/

/* $Id$ */

#ifndef PHP_MINHAEXTENSAO_H
#define PHP_MINHAEXTENSAO_H

extern zend_module_entry minhaextensao_module_entry;
#define phpext_minhaextensao_ptr &minhaextensao_module_entry

#ifdef PHP_WIN32
#	define PHP_MINHAEXTENSAO_API __declspec(dllexport)
#elif defined(__GNUC__) && __GNUC__ >= 4
#	define PHP_MINHAEXTENSAO_API __attribute__ ((visibility("default")))
#else
#	define PHP_MINHAEXTENSAO_API
#endif

#ifdef ZTS
#include "TSRM.h"
#endif

PHP_MINIT_FUNCTION(minhaextensao);
PHP_MSHUTDOWN_FUNCTION(minhaextensao);
PHP_RINIT_FUNCTION(minhaextensao);
PHP_RSHUTDOWN_FUNCTION(minhaextensao);
PHP_MINFO_FUNCTION(minhaextensao);

PHP_FUNCTION(minhaextensao_me_da_um_array);
PHP_FUNCTION(minhaextensao_string);
PHP_FUNCTION(minhaextensao_bool);
PHP_FUNCTION(minhaextensao_resource);
PHP_FUNCTION(minhaextensao_resource_check);
PHP_FUNCTION(minhaextensao_recebe_string_opcional);
PHP_FUNCTION(minhaextensao_recebe_string);


#ifdef ZTS
#define MINHAEXTENSAO_G(v) TSRMG(minhaextensao_globals_id, zend_minhaextensao_globals *, v)
#else
#define MINHAEXTENSAO_G(v) (minhaextensao_globals.v)
#endif

#endif


/*
 * Local variables:
 * tab-width: 4
 * c-basic-offset: 4
 * End:
 * vim600: noet sw=4 ts=4 fdm=marker
 * vim<600: noet sw=4 ts=4
 */
