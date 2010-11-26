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

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include <stdio.h>
#include "php.h"
#include "php_ini.h"
#include "ext/standard/info.h"
#include "php_minhaextensao.h"



static int le_minhaextensao;

const zend_function_entry minhaextensao_functions[] = {
    PHP_FE(minhaextensao_me_da_um_array, NULL)
    PHP_FE(minhaextensao_string, NULL)
    PHP_FE(minhaextensao_bool, NULL)
    PHP_FE(minhaextensao_recebe_string, NULL)
    PHP_FE(minhaextensao_recebe_string_opcional, NULL)
    PHP_FE(minhaextensao_resource, NULL)
    PHP_FE(minhaextensao_resource_check, NULL)
	{NULL, NULL, NULL}
};


zend_module_entry minhaextensao_module_entry = {
#if ZEND_MODULE_API_NO >= 20010901
	STANDARD_MODULE_HEADER,
#endif
	"minhaextensao",
	minhaextensao_functions,
	PHP_MINIT(minhaextensao),
	PHP_MSHUTDOWN(minhaextensao),
	PHP_RINIT(minhaextensao),	
	PHP_RSHUTDOWN(minhaextensao),
	PHP_MINFO(minhaextensao),
#if ZEND_MODULE_API_NO >= 20010901
	"0.1",
#endif
	STANDARD_MODULE_PROPERTIES
};


#ifdef COMPILE_DL_MINHAEXTENSAO
ZEND_GET_MODULE(minhaextensao)
#endif


PHP_INI_BEGIN()
    PHP_INI_ENTRY("minhaextensao.config", "Funciona mesmo!", PHP_INI_ALL, NULL)
PHP_INI_END();

static void php_minhaextensao_resource_destrutor(zend_rsrc_list_entry *rsrc TSRMLS_DC)
{
    FILE *fp = (FILE *) rsrc->ptr;
    fclose(fp);
}


PHP_MINIT_FUNCTION(minhaextensao)
{
    le_minhaextensao = zend_register_list_destructors_ex(
        php_minhaextensao_resource_destrutor, NULL, 
        "Resource da Minha Extensao", module_number);

    REGISTER_INI_ENTRIES();

    REGISTER_STRING_CONSTANT("MINHAEXTENSAO_HELLO",
        "Hello World\n", CONST_CS | CONST_PERSISTENT);

	return SUCCESS;
}


PHP_MSHUTDOWN_FUNCTION(minhaextensao)
{
    UNREGISTER_INI_ENTRIES();

	return SUCCESS;
}



PHP_RINIT_FUNCTION(minhaextensao)
{
	return SUCCESS;
}



PHP_RSHUTDOWN_FUNCTION(minhaextensao)
{
	return SUCCESS;
}


PHP_MINFO_FUNCTION(minhaextensao)
{
	php_info_print_table_start();
    php_printf(
        "<tr><td class=\"e\">"
        "<img src=\"http://ppadron.blog.br/4chan.jpg\"/>"
        "</td></tr>"
    );
	php_info_print_table_end();

    DISPLAY_INI_ENTRIES();

}


PHP_FUNCTION(minhaextensao_string)
{
    
}

PHP_FUNCTION(minhaextensao_bool)
{
/*    RETURN_TRUE; */
    php_error_docref(NULL TSRMLS_CC, E_WARNING, "Nunca vai chegar aqui");
}

PHP_FUNCTION(minhaextensao_me_da_um_array)
{
    zval *meu_primeiro_array;

    ALLOC_INIT_ZVAL(meu_primeiro_array);

    array_init(meu_primeiro_array);
    array_init(return_value);

    add_next_index_null(meu_primeiro_array);
    add_next_index_string(meu_primeiro_array, "ueeeba!!", 1);

    /* uau */
    add_next_index_zval(return_value, meu_primeiro_array);
}

PHP_FUNCTION(minhaextensao_recebe_string)
{
    char *param;
    int param_len;

    if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "s", &param, &param_len) == FAILURE) {
        return;
    }

    php_printf("Obrigado por me passar como parametro:");
    PHPWRITE(param, param_len);
    php_printf("\n");
}

PHP_FUNCTION(minhaextensao_recebe_string_opcional)
{
    char *str = "default";
    int str_len = sizeof("default") - 1;
    
    if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "|s", &str, &str_len) == FAILURE) {
        RETURN_FALSE;
    }

    php_printf("vejam: ");
    PHPWRITE(str, str_len);
    php_printf("\n");    
}

PHP_FUNCTION(minhaextensao_resource)
{
    FILE *fp;
    fp = fopen("/tmp/arquivo", "r");
    
    if (!fp) {
        php_error_docref(NULL TSRMLS_CC, E_WARNING, "Naaaaaao");
        RETURN_FALSE;
    }

    ZEND_REGISTER_RESOURCE(return_value, fp, le_minhaextensao);
}

PHP_FUNCTION(minhaextensao_resource_check)
{
    FILE *fp;
    zval *resource;

    if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "r", &resource) == FAILURE) {
        RETURN_NULL();
    }

    ZEND_FETCH_RESOURCE(fp, FILE*, &resource, -1,
        "Resource da Minha Extensao", le_minhaextensao);

    if (!fp) {
        RETURN_FALSE;
    }

    RETURN_TRUE;
}
