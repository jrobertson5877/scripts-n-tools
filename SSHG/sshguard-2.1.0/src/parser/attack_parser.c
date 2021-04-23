/* original parser id follows */
/* yysccsid[] = "@(#)yaccpar	1.9 (Berkeley) 02/21/93" */
/* (use YYMAJOR/YYMINOR for ifdefs dependent on parser version) */

#define YYBYACC 1
#define YYMAJOR 1
#define YYMINOR 9
#define YYPATCH 20170201

#define YYEMPTY        (-1)
#define yyclearin      (yychar = YYEMPTY)
#define yyerrok        (yyerrflag = 0)
#define YYRECOVERING() (yyerrflag != 0)
#define YYENOMEM       (-2)
#define YYEOF          0
#define YYPREFIX "yy"

#define YYPURE 0

#line 2 "attack_parser.y"

/*
 * Copyright (c) 2007,2008,2009,2010 Mij <mij@sshguard.net>
 *
 * Permission to use, copy, modify, and distribute this software for any
 * purpose with or without fee is hereby granted, provided that the above
 * copyright notice and this permission notice appear in all copies.
 *
 * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
 * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR
 * ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
 * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN
 * ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF
 * OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
 */

/*
 * SSHGuard. See http://www.sshguard.net
 */

#include <string.h>

#include "parser.h"

#define DEFAULT_ATTACKS_DANGEROUSNESS           10

 /* stuff exported by the scanner */
extern void scanner_init();
extern void scanner_fin();
extern int yylex();

static void yyerror(attack_t *, const char *);

#ifdef YYSTYPE
#undef  YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
#endif
#ifndef YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
#line 43 "attack_parser.y"
typedef union {
    char *str;
    int num;
} YYSTYPE;
#endif /* !YYSTYPE_IS_DECLARED */
#line 68 "attack_parser.c"

/* compatibility with bison */
#ifdef YYPARSE_PARAM
/* compatibility with FreeBSD */
# ifdef YYPARSE_PARAM_TYPE
#  define YYPARSE_DECL() yyparse(YYPARSE_PARAM_TYPE YYPARSE_PARAM)
# else
#  define YYPARSE_DECL() yyparse(void *YYPARSE_PARAM)
# endif
#else
# define YYPARSE_DECL() yyparse(attack_t *attack)
#endif

/* Parameters sent to lex. */
#ifdef YYLEX_PARAM
# define YYLEX_DECL() yylex(void *YYLEX_PARAM)
# define YYLEX yylex(YYLEX_PARAM)
#else
# define YYLEX_DECL() yylex(void)
# define YYLEX yylex()
#endif

/* Parameters sent to yyerror. */
#ifndef YYERROR_DECL
#define YYERROR_DECL() yyerror(attack_t *attack, const char *s)
#endif
#ifndef YYERROR_CALL
#define YYERROR_CALL(msg) yyerror(attack, msg)
#endif

extern int YYPARSE_DECL();

#define IPv4 257
#define IPv6 258
#define HOSTADDR 259
#define WORD 260
#define INTEGER 261
#define SYSLOG_BANNER_PID 262
#define SOCKLOG_BANNER_PID 263
#define SYSLOG_BANNER 264
#define TIMESTAMP_SYSLOG 265
#define TIMESTAMP_ISO8601 266
#define TIMESTAMP_TAI64 267
#define AT_TIMESTAMP_TAI64 268
#define METALOG_BANNER 269
#define SOCKLOG_BANNER 270
#define HTTP_REQUEST 271
#define HTTP_VERSION 272
#define HTTP_REDIRECT 273
#define HTTP_AUTHFAIL 274
#define HTTP_CLIERROR 275
#define HTTP_BOTSEARCH_WEBMAIL 276
#define HTTP_BOTSEARCH_PHPMYADMIN 277
#define HTTP_BOTSEARCH_WORDPRESS 278
#define HTTP_BOTSEARCH 279
#define SSH_INVALUSERPREF 280
#define SSH_NOTALLOWEDPREF 281
#define SSH_NOTALLOWEDSUFF 282
#define SSH_LOGINERR_PREF 283
#define SSH_LOGINERR_PAM 284
#define SSH_VIA 285
#define SSH_MAXAUTH 286
#define SSH_ADDR_SUFF 287
#define SSH_NOIDENTIFSTR 288
#define SSH_BADPROTOCOLIDENTIF 289
#define SSH_BADPROTOCOLIDENTIF_SUFF 290
#define SSH_BADKEX_PREF 291
#define SSH_BADKEX_SUFF 292
#define SSH_DISCONNECT_PREF 293
#define SSH_PREAUTH_SUFF 294
#define SSHGUARD_ATTACK_PREF 295
#define SSHGUARD_ATTACK_SUFF 296
#define SSHGUARD_BLOCK_PREF 297
#define SSHGUARD_BLOCK_SUFF 298
#define DOVECOT_IMAP_LOGINERR_PREF 299
#define DOVECOT_IMAP_LOGINERR_SUFF 300
#define UWIMAP_LOGINERR 301
#define CYRUSIMAP_SASL_LOGINERR_PREF 302
#define CYRUSIMAP_SASL_LOGINERR_SUFF 303
#define CUCIPOP_AUTHFAIL 304
#define EXIM_ESMTP_AUTHFAIL_PREF 305
#define EXIM_ESMTP_AUTHFAIL_SUFF 306
#define SENDMAIL_RELAYDENIED_PREF 307
#define SENDMAIL_RELAYDENIED_SUFF 308
#define SENDMAIL_AUTHFAILURE_PREF 309
#define SENDMAIL_AUTHFAILURE_SUFF 310
#define POSTFIX_NO_AUTH_PREF 311
#define POSTFIX_SASL_LOGINERR_PREF 312
#define POSTFIX_SASL_LOGINERR_SUFF 313
#define FREEBSDFTPD_LOGINERR_PREF 314
#define FREEBSDFTPD_LOGINERR_SUFF 315
#define PROFTPD_LOGINERR_PREF 316
#define PROFTPD_LOGINERR_SUFF 317
#define PUREFTPD_LOGINERR_PREF 318
#define PUREFTPD_LOGINERR_SUFF 319
#define VSFTPD_LOGINERR_PREF 320
#define VSFTPD_LOGINERR_SUFF 321
#define COCKPIT_AUTHFAIL_PREF 322
#define COCKPIT_AUTHFAIL_SUFF 323
#define CLF_REQUEST_PREF 324
#define CLF_UNAUTHOIRIZED_PREF 325
#define CLF_UNAUTHOIRIZED_SUFF 326
#define CLFWEBPROBES_BOTSEARCH_SUFF 327
#define CLF_WORDPRESS_SUFF 328
#define YYERRCODE 256
typedef int YYINT;
static const YYINT yylhs[] = {                           -1,
    0,    0,    0,    0,    0,    1,    1,    2,    3,    4,
    4,    5,    6,    6,    6,    6,    6,    6,    6,    6,
    6,    6,    6,    6,    6,    6,    6,    6,    6,   24,
   24,   24,    7,    7,    7,    7,    7,   25,   25,   25,
   26,   26,   26,   26,   27,   27,   28,   29,    8,    8,
    9,   10,   11,   12,   13,   14,   14,   15,   15,   16,
   17,   18,   19,   20,   21,   22,   23,
};
static const YYINT yylen[] = {                            2,
    1,    1,    1,    1,    1,    2,    2,    2,    2,    2,
    2,    1,    1,    1,    1,    1,    1,    1,    1,    1,
    1,    1,    1,    1,    1,    1,    1,    1,    1,    1,
    1,    1,    1,    1,    1,    1,    1,    2,    3,    3,
    3,    2,    3,    3,    2,    3,    3,    3,    3,    3,
    3,    4,    3,    2,    3,    3,    3,    3,    3,    3,
    3,    3,    3,    3,    3,    3,    3,
};
static const YYINT yydefred[] = {                         0,
   30,   31,   32,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    1,    2,    3,    4,    5,
   12,   13,   14,   15,   16,   17,   18,   19,   20,   21,
   22,   23,   24,   25,   26,   27,   28,   29,    0,   33,
   34,   35,   36,   37,    6,   10,    7,    8,    9,   11,
    0,    0,    0,    0,    0,   45,    0,    0,    0,    0,
    0,    0,    0,    0,   54,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,   39,   40,   41,
   43,   44,   47,   48,   46,   49,   50,   51,    0,   53,
   55,   56,   57,   59,   58,   60,   61,   62,   63,   64,
   66,   67,   65,   52,
};
static const YYINT yydgoto[] = {                         35,
   36,   37,   38,   39,   40,   41,   42,   43,   44,   45,
   46,   47,   48,   49,   50,   51,   52,   53,   54,   55,
   56,   57,   58,   59,   60,   61,   62,   63,   64,
};
static const YYINT yysindex[] = {                      -230,
    0,    0,    0, -164, -164, -164, -164, -164, -164, -222,
 -222, -222, -222, -222, -222, -222, -222, -222, -222, -222,
 -222,  -79, -222, -222, -222, -222, -222, -222, -222, -222,
 -222, -222, -222, -222,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0, -299,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
 -240, -234, -238, -233, -232,    0, -228, -235, -226, -236,
 -220, -224, -222, -239,    0, -223, -242, -225,  -23, -217,
 -218, -237, -221, -219, -216, -297, -227,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,   -6,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,
};
static const YYINT yyrindex[] = {                         0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
   89,    0,    0,   91,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,
};
static const YYINT yygindex[] = {                         0,
    0,    0,    0,    0,   37,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,  -10,    0,    0,    0,    0,    0,
};
#define YYTABLESIZE 158
static const YYINT yytable[] = {                         71,
   72,   73,   74,   75,   76,   77,   78,   79,   80,   81,
   82,   83,   84,   85,   86,   87,   88,   89,   90,   91,
   92,   93,   94,   95,   96,   97,    1,    2,    3,  121,
  122,    4,    5,    6,    1,    2,    3,    7,    8,    9,
   65,   66,   67,   68,   69,   70,   98,   99,  100,   10,
   11,  101,   12,   13,  102,   14,  104,   15,   16,  106,
   17,  103,   18,  110,   19,  112,   20,  105,   21,  114,
   22,   23,  109,   24,   25,  108,   26,  107,   27,  117,
   28,   29,  111,   30,  113,   31,  124,   32,   38,   33,
   42,   34,    1,    2,    3,  115,  116,  118,  123,    0,
    0,  119,    0,    0,    0,    0,  120,    0,    0,    0,
    0,    0,    0,    0,    0,   10,   11,    0,   12,   13,
    0,   14,    0,   15,   16,    0,   17,    0,   18,    0,
   19,    0,   20,    0,   21,    0,   22,   23,    0,   24,
   25,    0,   26,    0,   27,    0,   28,   29,    0,   30,
    0,   31,    0,   32,    0,   33,    0,   34,
};
static const YYINT yycheck[] = {                         10,
   11,   12,   13,   14,   15,   16,   17,   18,   19,   20,
   21,   91,   23,   24,   25,   26,   27,   28,   29,   30,
   31,   32,   33,   34,  324,  325,  257,  258,  259,  327,
  328,  262,  263,  264,  257,  258,  259,  268,  269,  270,
    4,    5,    6,    7,    8,    9,  287,  282,  287,  280,
  281,  285,  283,  284,  287,  286,  292,  288,  289,  296,
  291,  290,  293,  303,  295,  308,  297,  294,  299,   93,
  301,  302,   83,  304,  305,  300,  307,  298,  309,  317,
  311,  312,  306,  314,  310,  316,   93,  318,    0,  320,
    0,  322,  257,  258,  259,  313,  315,  319,  326,   -1,
   -1,  321,   -1,   -1,   -1,   -1,  323,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,  280,  281,   -1,  283,  284,
   -1,  286,   -1,  288,  289,   -1,  291,   -1,  293,   -1,
  295,   -1,  297,   -1,  299,   -1,  301,  302,   -1,  304,
  305,   -1,  307,   -1,  309,   -1,  311,  312,   -1,  314,
   -1,  316,   -1,  318,   -1,  320,   -1,  322,
};
#define YYFINAL 35
#ifndef YYDEBUG
#define YYDEBUG 0
#endif
#define YYMAXTOKEN 328
#define YYUNDFTOKEN 360
#define YYTRANSLATE(a) ((a) > YYMAXTOKEN ? YYUNDFTOKEN : (a))
#if YYDEBUG
static const char *const yyname[] = {

"end-of-file",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"'['",0,"']'",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"IPv4","IPv6","HOSTADDR",
"WORD","INTEGER","SYSLOG_BANNER_PID","SOCKLOG_BANNER_PID","SYSLOG_BANNER",
"TIMESTAMP_SYSLOG","TIMESTAMP_ISO8601","TIMESTAMP_TAI64","AT_TIMESTAMP_TAI64",
"METALOG_BANNER","SOCKLOG_BANNER","HTTP_REQUEST","HTTP_VERSION","HTTP_REDIRECT",
"HTTP_AUTHFAIL","HTTP_CLIERROR","HTTP_BOTSEARCH_WEBMAIL",
"HTTP_BOTSEARCH_PHPMYADMIN","HTTP_BOTSEARCH_WORDPRESS","HTTP_BOTSEARCH",
"SSH_INVALUSERPREF","SSH_NOTALLOWEDPREF","SSH_NOTALLOWEDSUFF",
"SSH_LOGINERR_PREF","SSH_LOGINERR_PAM","SSH_VIA","SSH_MAXAUTH","SSH_ADDR_SUFF",
"SSH_NOIDENTIFSTR","SSH_BADPROTOCOLIDENTIF","SSH_BADPROTOCOLIDENTIF_SUFF",
"SSH_BADKEX_PREF","SSH_BADKEX_SUFF","SSH_DISCONNECT_PREF","SSH_PREAUTH_SUFF",
"SSHGUARD_ATTACK_PREF","SSHGUARD_ATTACK_SUFF","SSHGUARD_BLOCK_PREF",
"SSHGUARD_BLOCK_SUFF","DOVECOT_IMAP_LOGINERR_PREF","DOVECOT_IMAP_LOGINERR_SUFF",
"UWIMAP_LOGINERR","CYRUSIMAP_SASL_LOGINERR_PREF","CYRUSIMAP_SASL_LOGINERR_SUFF",
"CUCIPOP_AUTHFAIL","EXIM_ESMTP_AUTHFAIL_PREF","EXIM_ESMTP_AUTHFAIL_SUFF",
"SENDMAIL_RELAYDENIED_PREF","SENDMAIL_RELAYDENIED_SUFF",
"SENDMAIL_AUTHFAILURE_PREF","SENDMAIL_AUTHFAILURE_SUFF","POSTFIX_NO_AUTH_PREF",
"POSTFIX_SASL_LOGINERR_PREF","POSTFIX_SASL_LOGINERR_SUFF",
"FREEBSDFTPD_LOGINERR_PREF","FREEBSDFTPD_LOGINERR_SUFF","PROFTPD_LOGINERR_PREF",
"PROFTPD_LOGINERR_SUFF","PUREFTPD_LOGINERR_PREF","PUREFTPD_LOGINERR_SUFF",
"VSFTPD_LOGINERR_PREF","VSFTPD_LOGINERR_SUFF","COCKPIT_AUTHFAIL_PREF",
"COCKPIT_AUTHFAIL_SUFF","CLF_REQUEST_PREF","CLF_UNAUTHOIRIZED_PREF",
"CLF_UNAUTHOIRIZED_SUFF","CLFWEBPROBES_BOTSEARCH_SUFF","CLF_WORDPRESS_SUFF",0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"illegal-symbol",
};
static const char *const yyrule[] = {
"$accept : text",
"text : syslogent",
"text : multilogent",
"text : metalogent",
"text : socklogent",
"text : logmsg",
"syslogent : SYSLOG_BANNER_PID logmsg",
"syslogent : SYSLOG_BANNER logmsg",
"multilogent : AT_TIMESTAMP_TAI64 logmsg",
"metalogent : METALOG_BANNER logmsg",
"socklogent : SOCKLOG_BANNER_PID logmsg",
"socklogent : SOCKLOG_BANNER logmsg",
"logmsg : msg_single",
"msg_single : sshmsg",
"msg_single : sshguardmsg",
"msg_single : dovecotmsg",
"msg_single : uwimapmsg",
"msg_single : cyrusimapmsg",
"msg_single : cucipopmsg",
"msg_single : eximmsg",
"msg_single : sendmailmsg",
"msg_single : postfixmsg",
"msg_single : freebsdftpdmsg",
"msg_single : proftpdmsg",
"msg_single : pureftpdmsg",
"msg_single : vsftpdmsg",
"msg_single : cockpitmsg",
"msg_single : clfunauhtdmsg",
"msg_single : clfwebprobesmsg",
"msg_single : clfwordpressmsg",
"addr : IPv4",
"addr : IPv6",
"addr : HOSTADDR",
"sshmsg : ssh_illegaluser",
"sshmsg : ssh_authfail",
"sshmsg : ssh_noidentifstring",
"sshmsg : ssh_badprotocol",
"sshmsg : ssh_badkex",
"ssh_illegaluser : SSH_INVALUSERPREF addr",
"ssh_illegaluser : SSH_INVALUSERPREF addr SSH_ADDR_SUFF",
"ssh_illegaluser : SSH_NOTALLOWEDPREF addr SSH_NOTALLOWEDSUFF",
"ssh_authfail : SSH_LOGINERR_PREF addr SSH_ADDR_SUFF",
"ssh_authfail : SSH_LOGINERR_PAM addr",
"ssh_authfail : SSH_LOGINERR_PAM addr SSH_VIA",
"ssh_authfail : SSH_MAXAUTH addr SSH_ADDR_SUFF",
"ssh_noidentifstring : SSH_NOIDENTIFSTR addr",
"ssh_noidentifstring : SSH_DISCONNECT_PREF addr SSH_PREAUTH_SUFF",
"ssh_badprotocol : SSH_BADPROTOCOLIDENTIF addr SSH_BADPROTOCOLIDENTIF_SUFF",
"ssh_badkex : SSH_BADKEX_PREF addr SSH_BADKEX_SUFF",
"sshguardmsg : SSHGUARD_ATTACK_PREF addr SSHGUARD_ATTACK_SUFF",
"sshguardmsg : SSHGUARD_BLOCK_PREF addr SSHGUARD_BLOCK_SUFF",
"dovecotmsg : DOVECOT_IMAP_LOGINERR_PREF addr DOVECOT_IMAP_LOGINERR_SUFF",
"uwimapmsg : UWIMAP_LOGINERR '[' addr ']'",
"cyrusimapmsg : CYRUSIMAP_SASL_LOGINERR_PREF addr CYRUSIMAP_SASL_LOGINERR_SUFF",
"cucipopmsg : CUCIPOP_AUTHFAIL addr",
"eximmsg : EXIM_ESMTP_AUTHFAIL_PREF addr EXIM_ESMTP_AUTHFAIL_SUFF",
"sendmailmsg : SENDMAIL_RELAYDENIED_PREF addr SENDMAIL_RELAYDENIED_SUFF",
"sendmailmsg : SENDMAIL_AUTHFAILURE_PREF addr SENDMAIL_AUTHFAILURE_SUFF",
"postfixmsg : POSTFIX_SASL_LOGINERR_PREF addr POSTFIX_SASL_LOGINERR_SUFF",
"postfixmsg : POSTFIX_NO_AUTH_PREF addr ']'",
"freebsdftpdmsg : FREEBSDFTPD_LOGINERR_PREF addr FREEBSDFTPD_LOGINERR_SUFF",
"proftpdmsg : PROFTPD_LOGINERR_PREF addr PROFTPD_LOGINERR_SUFF",
"pureftpdmsg : PUREFTPD_LOGINERR_PREF addr PUREFTPD_LOGINERR_SUFF",
"vsftpdmsg : VSFTPD_LOGINERR_PREF addr VSFTPD_LOGINERR_SUFF",
"cockpitmsg : COCKPIT_AUTHFAIL_PREF addr COCKPIT_AUTHFAIL_SUFF",
"clfunauhtdmsg : addr CLF_UNAUTHOIRIZED_PREF CLF_UNAUTHOIRIZED_SUFF",
"clfwebprobesmsg : addr CLF_REQUEST_PREF CLFWEBPROBES_BOTSEARCH_SUFF",
"clfwordpressmsg : addr CLF_REQUEST_PREF CLF_WORDPRESS_SUFF",

};
#endif

int      yydebug;
int      yynerrs;

int      yyerrflag;
int      yychar;
YYSTYPE  yyval;
YYSTYPE  yylval;

/* define the initial stack-sizes */
#ifdef YYSTACKSIZE
#undef YYMAXDEPTH
#define YYMAXDEPTH  YYSTACKSIZE
#else
#ifdef YYMAXDEPTH
#define YYSTACKSIZE YYMAXDEPTH
#else
#define YYSTACKSIZE 10000
#define YYMAXDEPTH  10000
#endif
#endif

#define YYINITSTACKSIZE 200

typedef struct {
    unsigned stacksize;
    YYINT    *s_base;
    YYINT    *s_mark;
    YYINT    *s_last;
    YYSTYPE  *l_base;
    YYSTYPE  *l_mark;
} YYSTACKDATA;
/* variables for the parser stack */
static YYSTACKDATA yystack;
#line 307 "attack_parser.y"

static void yyerror(__attribute__((unused)) attack_t *a,
    __attribute__((unused)) const char *s) { /* do nothing */ }

int parse_line(char *str, attack_t *attack) {

    /* TODO: reduce danger for SERVICES_CLF_PROBES */
    attack->dangerousness = DEFAULT_ATTACKS_DANGEROUSNESS;

    scanner_init(str);
    int ret = yyparse(attack);
    scanner_fin();

    return ret;
}
#line 447 "attack_parser.c"

#if YYDEBUG
#include <stdio.h>	/* needed for printf */
#endif

#include <stdlib.h>	/* needed for malloc, etc */
#include <string.h>	/* needed for memset */

/* allocate initial stack or double stack size, up to YYMAXDEPTH */
static int yygrowstack(YYSTACKDATA *data)
{
    int i;
    unsigned newsize;
    YYINT *newss;
    YYSTYPE *newvs;

    if ((newsize = data->stacksize) == 0)
        newsize = YYINITSTACKSIZE;
    else if (newsize >= YYMAXDEPTH)
        return YYENOMEM;
    else if ((newsize *= 2) > YYMAXDEPTH)
        newsize = YYMAXDEPTH;

    i = (int) (data->s_mark - data->s_base);
    newss = (YYINT *)realloc(data->s_base, newsize * sizeof(*newss));
    if (newss == 0)
        return YYENOMEM;

    data->s_base = newss;
    data->s_mark = newss + i;

    newvs = (YYSTYPE *)realloc(data->l_base, newsize * sizeof(*newvs));
    if (newvs == 0)
        return YYENOMEM;

    data->l_base = newvs;
    data->l_mark = newvs + i;

    data->stacksize = newsize;
    data->s_last = data->s_base + newsize - 1;
    return 0;
}

#if YYPURE || defined(YY_NO_LEAKS)
static void yyfreestack(YYSTACKDATA *data)
{
    free(data->s_base);
    free(data->l_base);
    memset(data, 0, sizeof(*data));
}
#else
#define yyfreestack(data) /* nothing */
#endif

#define YYABORT  goto yyabort
#define YYREJECT goto yyabort
#define YYACCEPT goto yyaccept
#define YYERROR  goto yyerrlab

int
YYPARSE_DECL()
{
    int yym, yyn, yystate;
#if YYDEBUG
    const char *yys;

    if ((yys = getenv("YYDEBUG")) != 0)
    {
        yyn = *yys;
        if (yyn >= '0' && yyn <= '9')
            yydebug = yyn - '0';
    }
#endif

    yym = 0;
    yyn = 0;
    yynerrs = 0;
    yyerrflag = 0;
    yychar = YYEMPTY;
    yystate = 0;

#if YYPURE
    memset(&yystack, 0, sizeof(yystack));
#endif

    if (yystack.s_base == NULL && yygrowstack(&yystack) == YYENOMEM) goto yyoverflow;
    yystack.s_mark = yystack.s_base;
    yystack.l_mark = yystack.l_base;
    yystate = 0;
    *yystack.s_mark = 0;

yyloop:
    if ((yyn = yydefred[yystate]) != 0) goto yyreduce;
    if (yychar < 0)
    {
        yychar = YYLEX;
        if (yychar < 0) yychar = YYEOF;
#if YYDEBUG
        if (yydebug)
        {
            if ((yys = yyname[YYTRANSLATE(yychar)]) == NULL) yys = yyname[YYUNDFTOKEN];
            printf("%sdebug: state %d, reading %d (%s)\n",
                    YYPREFIX, yystate, yychar, yys);
        }
#endif
    }
    if (((yyn = yysindex[yystate]) != 0) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == (YYINT) yychar)
    {
#if YYDEBUG
        if (yydebug)
            printf("%sdebug: state %d, shifting to state %d\n",
                    YYPREFIX, yystate, yytable[yyn]);
#endif
        if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack) == YYENOMEM) goto yyoverflow;
        yystate = yytable[yyn];
        *++yystack.s_mark = yytable[yyn];
        *++yystack.l_mark = yylval;
        yychar = YYEMPTY;
        if (yyerrflag > 0)  --yyerrflag;
        goto yyloop;
    }
    if (((yyn = yyrindex[yystate]) != 0) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == (YYINT) yychar)
    {
        yyn = yytable[yyn];
        goto yyreduce;
    }
    if (yyerrflag != 0) goto yyinrecovery;

    YYERROR_CALL("syntax error");

    goto yyerrlab; /* redundant goto avoids 'unused label' warning */
yyerrlab:
    ++yynerrs;

yyinrecovery:
    if (yyerrflag < 3)
    {
        yyerrflag = 3;
        for (;;)
        {
            if (((yyn = yysindex[*yystack.s_mark]) != 0) && (yyn += YYERRCODE) >= 0 &&
                    yyn <= YYTABLESIZE && yycheck[yyn] == (YYINT) YYERRCODE)
            {
#if YYDEBUG
                if (yydebug)
                    printf("%sdebug: state %d, error recovery shifting\
 to state %d\n", YYPREFIX, *yystack.s_mark, yytable[yyn]);
#endif
                if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack) == YYENOMEM) goto yyoverflow;
                yystate = yytable[yyn];
                *++yystack.s_mark = yytable[yyn];
                *++yystack.l_mark = yylval;
                goto yyloop;
            }
            else
            {
#if YYDEBUG
                if (yydebug)
                    printf("%sdebug: error recovery discarding state %d\n",
                            YYPREFIX, *yystack.s_mark);
#endif
                if (yystack.s_mark <= yystack.s_base) goto yyabort;
                --yystack.s_mark;
                --yystack.l_mark;
            }
        }
    }
    else
    {
        if (yychar == YYEOF) goto yyabort;
#if YYDEBUG
        if (yydebug)
        {
            if ((yys = yyname[YYTRANSLATE(yychar)]) == NULL) yys = yyname[YYUNDFTOKEN];
            printf("%sdebug: state %d, error recovery discards token %d (%s)\n",
                    YYPREFIX, yystate, yychar, yys);
        }
#endif
        yychar = YYEMPTY;
        goto yyloop;
    }

yyreduce:
#if YYDEBUG
    if (yydebug)
        printf("%sdebug: state %d, reducing by rule %d (%s)\n",
                YYPREFIX, yystate, yyn, yyrule[yyn]);
#endif
    yym = yylen[yyn];
    if (yym > 0)
        yyval = yystack.l_mark[1-yym];
    else
        memset(&yyval, 0, sizeof yyval);

    switch (yyn)
    {
case 13:
#line 150 "attack_parser.y"
	{   attack->service = SERVICES_SSH; }
break;
case 14:
#line 151 "attack_parser.y"
	{   attack->service = SERVICES_SSHGUARD; }
break;
case 15:
#line 152 "attack_parser.y"
	{   attack->service = SERVICES_DOVECOT; }
break;
case 16:
#line 153 "attack_parser.y"
	{   attack->service = SERVICES_UWIMAP; }
break;
case 17:
#line 154 "attack_parser.y"
	{   attack->service = SERVICES_CYRUSIMAP; }
break;
case 18:
#line 155 "attack_parser.y"
	{   attack->service = SERVICES_CUCIPOP; }
break;
case 19:
#line 156 "attack_parser.y"
	{   attack->service = SERVICES_EXIM; }
break;
case 20:
#line 157 "attack_parser.y"
	{   attack->service = SERVICES_SENDMAIL; }
break;
case 21:
#line 158 "attack_parser.y"
	{   attack->service = SERVICES_POSTFIX; }
break;
case 22:
#line 159 "attack_parser.y"
	{   attack->service = SERVICES_FREEBSDFTPD; }
break;
case 23:
#line 160 "attack_parser.y"
	{   attack->service = SERVICES_PROFTPD; }
break;
case 24:
#line 161 "attack_parser.y"
	{   attack->service = SERVICES_PUREFTPD; }
break;
case 25:
#line 162 "attack_parser.y"
	{   attack->service = SERVICES_VSFTPD; }
break;
case 26:
#line 163 "attack_parser.y"
	{   attack->service = SERVICES_COCKPIT; }
break;
case 27:
#line 164 "attack_parser.y"
	{   attack->service = SERVICES_CLF_UNAUTH; }
break;
case 28:
#line 165 "attack_parser.y"
	{   attack->service = SERVICES_CLF_PROBES; }
break;
case 29:
#line 166 "attack_parser.y"
	{   attack->service = SERVICES_CLF_WORDPRESS; }
break;
case 30:
#line 171 "attack_parser.y"
	{
                        attack->address.kind = ADDRKIND_IPv4;
                        strcpy(attack->address.value, yystack.l_mark[0].str);
                    }
break;
case 31:
#line 175 "attack_parser.y"
	{
                        attack->address.kind = ADDRKIND_IPv6;
                        strcpy(attack->address.value, yystack.l_mark[0].str);
                    }
break;
case 32:
#line 179 "attack_parser.y"
	{
                        if (!attack_from_hostname(attack, yystack.l_mark[0].str)) {
                            YYABORT;
                        }
                    }
break;
#line 736 "attack_parser.c"
    }
    yystack.s_mark -= yym;
    yystate = *yystack.s_mark;
    yystack.l_mark -= yym;
    yym = yylhs[yyn];
    if (yystate == 0 && yym == 0)
    {
#if YYDEBUG
        if (yydebug)
            printf("%sdebug: after reduction, shifting from state 0 to\
 state %d\n", YYPREFIX, YYFINAL);
#endif
        yystate = YYFINAL;
        *++yystack.s_mark = YYFINAL;
        *++yystack.l_mark = yyval;
        if (yychar < 0)
        {
            yychar = YYLEX;
            if (yychar < 0) yychar = YYEOF;
#if YYDEBUG
            if (yydebug)
            {
                if ((yys = yyname[YYTRANSLATE(yychar)]) == NULL) yys = yyname[YYUNDFTOKEN];
                printf("%sdebug: state %d, reading %d (%s)\n",
                        YYPREFIX, YYFINAL, yychar, yys);
            }
#endif
        }
        if (yychar == YYEOF) goto yyaccept;
        goto yyloop;
    }
    if (((yyn = yygindex[yym]) != 0) && (yyn += yystate) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == (YYINT) yystate)
        yystate = yytable[yyn];
    else
        yystate = yydgoto[yym];
#if YYDEBUG
    if (yydebug)
        printf("%sdebug: after reduction, shifting from state %d \
to state %d\n", YYPREFIX, *yystack.s_mark, yystate);
#endif
    if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack) == YYENOMEM) goto yyoverflow;
    *++yystack.s_mark = (YYINT) yystate;
    *++yystack.l_mark = yyval;
    goto yyloop;

yyoverflow:
    YYERROR_CALL("yacc stack overflow");

yyabort:
    yyfreestack(&yystack);
    return (1);

yyaccept:
    yyfreestack(&yystack);
    return (0);
}
