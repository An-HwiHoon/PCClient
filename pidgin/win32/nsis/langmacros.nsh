!define GCOMPRIS_NSIS_INCLUDE_PATH "."

  ;; English goes first because its the default. The rest are
  ;; in alphabetical order (at least the strings actually displayed
  ;; will be).
  !insertmacro MUI_LANGUAGE "English"
  !insertmacro MUI_LANGUAGE "PortugueseBR"
  !insertmacro MUI_LANGUAGE "Basque"
  !insertmacro MUI_LANGUAGE "Ukrainian"
  !insertmacro MUI_LANGUAGE "NorwegianNynorsk"
  !insertmacro MUI_LANGUAGE "Italian"
  !insertmacro MUI_LANGUAGE "Slovenian"
  !insertmacro MUI_LANGUAGE "Estonian"
  !insertmacro MUI_LANGUAGE "Russian"
  !insertmacro MUI_LANGUAGE "Kurdish"
  !insertmacro MUI_LANGUAGE "Hungarian"
  !insertmacro MUI_LANGUAGE "Spanish"
  !insertmacro MUI_LANGUAGE "Lithuanian"
  !insertmacro MUI_LANGUAGE "Slovak"
  !insertmacro MUI_LANGUAGE "Romanian"
  !insertmacro MUI_LANGUAGE "Afrikaans"
  !insertmacro MUI_LANGUAGE "SimpChinese"
  !insertmacro MUI_LANGUAGE "Swedish"
  !insertmacro MUI_LANGUAGE "Irish"
  !insertmacro MUI_LANGUAGE "Dutch"
  !insertmacro MUI_LANGUAGE "Arabic"
  !insertmacro MUI_LANGUAGE "French"
  !insertmacro MUI_LANGUAGE "Albanian"
  !insertmacro MUI_LANGUAGE "Japanese"
  !insertmacro MUI_LANGUAGE "Polish"
  !insertmacro MUI_LANGUAGE "Danish"
  !insertmacro MUI_LANGUAGE "Hebrew"
  !insertmacro MUI_LANGUAGE "Greek"
  !insertmacro MUI_LANGUAGE "German"
  !insertmacro MUI_LANGUAGE "Portuguese"
  !insertmacro MUI_LANGUAGE "Catalan"
  !insertmacro MUI_LANGUAGE "Czech"
  !insertmacro MUI_LANGUAGE "Norwegian"
  !insertmacro MUI_LANGUAGE "TradChinese"
  !insertmacro MUI_LANGUAGE "Finnish"

;--------------------------------
;Translations
  !define GCOMPRIS_DEFAULT_LANGFILE "${GCOMPRIS_NSIS_INCLUDE_PATH}\translations\en.nsh"
;;
;; Windows GCompris NSIS installer language macros
;;

!macro GCOMPRIS_MACRO_DEFAULT_STRING LABEL VALUE
  !ifndef "${LABEL}"
    !define "${LABEL}" "${VALUE}"
    !ifdef INSERT_DEFAULT
      !warning "${LANG} lang file missing ${LABEL}, using default..."
    !endif
  !endif
!macroend

!macro GCOMPRIS_MACRO_LANGSTRING_INSERT LABEL LANG
  LangString "${LABEL}" "${LANG_${LANG}}" "${${LABEL}}"
  !undef "${LABEL}"
!macroend

!macro GCOMPRIS_MACRO_LANGUAGEFILE_BEGIN LANG
  !define CUR_LANG "${LANG}"
!macroend

!macro GCOMPRIS_MACRO_LANGUAGEFILE_END
  !define INSERT_DEFAULT
  !include "${GCOMPRIS_DEFAULT_LANGFILE}"
  !undef INSERT_DEFAULT

  ; String labels should match those from the default language file.
  !insertmacro GCOMPRIS_MACRO_LANGSTRING_INSERT TRANSLATIONSSECTIONTITLE ${CUR_LANG}
  !insertmacro GCOMPRIS_MACRO_LANGSTRING_INSERT PIDGINSECTIONTITLE ${CUR_LANG}
  !insertmacro GCOMPRIS_MACRO_LANGSTRING_INSERT PIDGINDEBUGSYMBOLSERROR ${CUR_LANG}
  !insertmacro GCOMPRIS_MACRO_LANGSTRING_INSERT PIDGINSECTIONDESCRIPTION ${CUR_LANG}
  !insertmacro GCOMPRIS_MACRO_LANGSTRING_INSERT DEBUGSYMBOLSSECTIONTITLE ${CUR_LANG}
  !insertmacro GCOMPRIS_MACRO_LANGSTRING_INSERT URIHANDLERSSECTIONTITLE ${CUR_LANG}
  !insertmacro GCOMPRIS_MACRO_LANGSTRING_INSERT GTKSECTIONTITLE ${CUR_LANG}
  !insertmacro GCOMPRIS_MACRO_LANGSTRING_INSERT PIDGINDESKTOPSHORTCUTDESC ${CUR_LANG}
  !insertmacro GCOMPRIS_MACRO_LANGSTRING_INSERT PIDGINPROMPTFORCENOGTK ${CUR_LANG}
  !insertmacro GCOMPRIS_MACRO_LANGSTRING_INSERT PIDGINSHORTCUTSSECTIONTITLE ${CUR_LANG}
  !insertmacro GCOMPRIS_MACRO_LANGSTRING_INSERT PIDGINSPELLCHECKSECTIONDESCRIPTION ${CUR_LANG}
  !insertmacro GCOMPRIS_MACRO_LANGSTRING_INSERT PIDGINSPELLCHECKERROR ${CUR_LANG}
  !insertmacro GCOMPRIS_MACRO_LANGSTRING_INSERT PIDGINDESKTOPSHORTCUTSECTIONTITLE ${CUR_LANG}
  !insertmacro GCOMPRIS_MACRO_LANGSTRING_INSERT PIDGINISRUNNING ${CUR_LANG}
  !insertmacro GCOMPRIS_MACRO_LANGSTRING_INSERT PIDGINUNINSTALLERROR2 ${CUR_LANG}
  !insertmacro GCOMPRIS_MACRO_LANGSTRING_INSERT PIDGINFINISHVISITWEBSITE ${CUR_LANG}
  !insertmacro GCOMPRIS_MACRO_LANGSTRING_INSERT PIDGINSPELLCHECKSECTIONTITLE ${CUR_LANG}
  !insertmacro GCOMPRIS_MACRO_LANGSTRING_INSERT PIDGINSTARTMENUSHORTCUTDESC ${CUR_LANG}
  !insertmacro GCOMPRIS_MACRO_LANGSTRING_INSERT PIDGINSHORTCUTSSECTIONDESCRIPTION ${CUR_LANG}
  !insertmacro GCOMPRIS_MACRO_LANGSTRING_INSERT PIDGINUNINSTALLERROR1 ${CUR_LANG}
  !insertmacro GCOMPRIS_MACRO_LANGSTRING_INSERT PIDGINLICENSEBUTTON ${CUR_LANG}
  !insertmacro GCOMPRIS_MACRO_LANGSTRING_INSERT PIDGINPROMPTCONTINUEWITHOUTUNINSTALL ${CUR_LANG}
  !insertmacro GCOMPRIS_MACRO_LANGSTRING_INSERT PIDGINSTARTMENUSHORTCUTSECTIONTITLE ${CUR_LANG}
  !insertmacro GCOMPRIS_MACRO_LANGSTRING_INSERT PIDGINGTKDOWNLOADERROR ${CUR_LANG}
  !insertmacro GCOMPRIS_MACRO_LANGSTRING_INSERT GTKSECTIONDESCRIPTION ${CUR_LANG}
  !insertmacro GCOMPRIS_MACRO_LANGSTRING_INSERT PIDGINLICENSEBOTTOMTEXT ${CUR_LANG}
  !insertmacro GCOMPRIS_MACRO_LANGSTRING_INSERT INSTALLERISRUNNING ${CUR_LANG}

  !undef CUR_LANG
!macroend

!macro GCOMPRIS_MACRO_INCLUDE_LANGFILE LANG FILE
  !insertmacro GCOMPRIS_MACRO_LANGUAGEFILE_BEGIN "${LANG}"
  !include "${FILE}"
  !insertmacro GCOMPRIS_MACRO_LANGUAGEFILE_END
!macroend
  !insertmacro GCOMPRIS_MACRO_INCLUDE_LANGFILE "ENGLISH" "${GCOMPRIS_NSIS_INCLUDE_PATH}\translations\en.nsh"
  !insertmacro GCOMPRIS_MACRO_INCLUDE_LANGFILE "PORTUGUESEBR" "${GCOMPRIS_NSIS_INCLUDE_PATH}\translations\pt_BR.nsh"
  !insertmacro GCOMPRIS_MACRO_INCLUDE_LANGFILE "BASQUE" "${GCOMPRIS_NSIS_INCLUDE_PATH}\translations\eu.nsh"
  !insertmacro GCOMPRIS_MACRO_INCLUDE_LANGFILE "UKRAINIAN" "${GCOMPRIS_NSIS_INCLUDE_PATH}\translations\uk.nsh"
  !insertmacro GCOMPRIS_MACRO_INCLUDE_LANGFILE "NORWEGIANNYNORSK" "${GCOMPRIS_NSIS_INCLUDE_PATH}\translations\nn.nsh"
  !insertmacro GCOMPRIS_MACRO_INCLUDE_LANGFILE "ITALIAN" "${GCOMPRIS_NSIS_INCLUDE_PATH}\translations\it.nsh"
  !insertmacro GCOMPRIS_MACRO_INCLUDE_LANGFILE "SLOVENIAN" "${GCOMPRIS_NSIS_INCLUDE_PATH}\translations\sl.nsh"
  !insertmacro GCOMPRIS_MACRO_INCLUDE_LANGFILE "ESTONIAN" "${GCOMPRIS_NSIS_INCLUDE_PATH}\translations\et.nsh"
  !insertmacro GCOMPRIS_MACRO_INCLUDE_LANGFILE "RUSSIAN" "${GCOMPRIS_NSIS_INCLUDE_PATH}\translations\ru.nsh"
  !insertmacro GCOMPRIS_MACRO_INCLUDE_LANGFILE "KURDISH" "${GCOMPRIS_NSIS_INCLUDE_PATH}\translations\ku.nsh"
  !insertmacro GCOMPRIS_MACRO_INCLUDE_LANGFILE "HUNGARIAN" "${GCOMPRIS_NSIS_INCLUDE_PATH}\translations\hu.nsh"
  !insertmacro GCOMPRIS_MACRO_INCLUDE_LANGFILE "SPANISH" "${GCOMPRIS_NSIS_INCLUDE_PATH}\translations\es.nsh"
  !insertmacro GCOMPRIS_MACRO_INCLUDE_LANGFILE "LITHUANIAN" "${GCOMPRIS_NSIS_INCLUDE_PATH}\translations\lt.nsh"
  !insertmacro GCOMPRIS_MACRO_INCLUDE_LANGFILE "SLOVAK" "${GCOMPRIS_NSIS_INCLUDE_PATH}\translations\sk.nsh"
  !insertmacro GCOMPRIS_MACRO_INCLUDE_LANGFILE "ROMANIAN" "${GCOMPRIS_NSIS_INCLUDE_PATH}\translations\ro.nsh"
  !insertmacro GCOMPRIS_MACRO_INCLUDE_LANGFILE "AFRIKAANS" "${GCOMPRIS_NSIS_INCLUDE_PATH}\translations\af.nsh"
  !insertmacro GCOMPRIS_MACRO_INCLUDE_LANGFILE "SIMPCHINESE" "${GCOMPRIS_NSIS_INCLUDE_PATH}\translations\zh_CN.nsh"
  !insertmacro GCOMPRIS_MACRO_INCLUDE_LANGFILE "SWEDISH" "${GCOMPRIS_NSIS_INCLUDE_PATH}\translations\sv.nsh"
  !insertmacro GCOMPRIS_MACRO_INCLUDE_LANGFILE "IRISH" "${GCOMPRIS_NSIS_INCLUDE_PATH}\translations\ga.nsh"
  !insertmacro GCOMPRIS_MACRO_INCLUDE_LANGFILE "DUTCH" "${GCOMPRIS_NSIS_INCLUDE_PATH}\translations\nl.nsh"
  !insertmacro GCOMPRIS_MACRO_INCLUDE_LANGFILE "ARABIC" "${GCOMPRIS_NSIS_INCLUDE_PATH}\translations\ar.nsh"
  !insertmacro GCOMPRIS_MACRO_INCLUDE_LANGFILE "FRENCH" "${GCOMPRIS_NSIS_INCLUDE_PATH}\translations\fr.nsh"
  !insertmacro GCOMPRIS_MACRO_INCLUDE_LANGFILE "ALBANIAN" "${GCOMPRIS_NSIS_INCLUDE_PATH}\translations\sq.nsh"
  !insertmacro GCOMPRIS_MACRO_INCLUDE_LANGFILE "JAPANESE" "${GCOMPRIS_NSIS_INCLUDE_PATH}\translations\ja.nsh"
  !insertmacro GCOMPRIS_MACRO_INCLUDE_LANGFILE "POLISH" "${GCOMPRIS_NSIS_INCLUDE_PATH}\translations\pl.nsh"
  !insertmacro GCOMPRIS_MACRO_INCLUDE_LANGFILE "DANISH" "${GCOMPRIS_NSIS_INCLUDE_PATH}\translations\da.nsh"
  !insertmacro GCOMPRIS_MACRO_INCLUDE_LANGFILE "HEBREW" "${GCOMPRIS_NSIS_INCLUDE_PATH}\translations\he.nsh"
  !insertmacro GCOMPRIS_MACRO_INCLUDE_LANGFILE "GREEK" "${GCOMPRIS_NSIS_INCLUDE_PATH}\translations\el.nsh"
  !insertmacro GCOMPRIS_MACRO_INCLUDE_LANGFILE "GERMAN" "${GCOMPRIS_NSIS_INCLUDE_PATH}\translations\de.nsh"
  !insertmacro GCOMPRIS_MACRO_INCLUDE_LANGFILE "PORTUGUESE" "${GCOMPRIS_NSIS_INCLUDE_PATH}\translations\pt.nsh"
  !insertmacro GCOMPRIS_MACRO_INCLUDE_LANGFILE "CATALAN" "${GCOMPRIS_NSIS_INCLUDE_PATH}\translations\ca.nsh"
  !insertmacro GCOMPRIS_MACRO_INCLUDE_LANGFILE "CZECH" "${GCOMPRIS_NSIS_INCLUDE_PATH}\translations\cs.nsh"
  !insertmacro GCOMPRIS_MACRO_INCLUDE_LANGFILE "NORWEGIAN" "${GCOMPRIS_NSIS_INCLUDE_PATH}\translations\nb.nsh"
  !insertmacro GCOMPRIS_MACRO_INCLUDE_LANGFILE "TRADCHINESE" "${GCOMPRIS_NSIS_INCLUDE_PATH}\translations\zh_TW.nsh"
  !insertmacro GCOMPRIS_MACRO_INCLUDE_LANGFILE "FINNISH" "${GCOMPRIS_NSIS_INCLUDE_PATH}\translations\fi.nsh"

!macro SELECT_TRANSLATION_SECTION LANG_NAME LANG_CODE
  StrCmp "$LANGUAGE" "${LANG_${LANG_NAME}}" 0 end_${LANG_CODE}
  !insertmacro SelectSection ${SecLang_${LANG_CODE}}
  Goto done
  end_${LANG_CODE}:
!macroend
; Convert the current $LANGUAGE to a language code that we can use for translation mo selection
; If there's a better way to do this, I'd love to know it
!macro SELECT_TRANSLATION_FUNCTION
  !insertmacro SELECT_TRANSLATION_SECTION "PORTUGUESEBR" "pt_BR"
  !insertmacro SELECT_TRANSLATION_SECTION "BASQUE" "eu"
  !insertmacro SELECT_TRANSLATION_SECTION "UKRAINIAN" "uk"
  !insertmacro SELECT_TRANSLATION_SECTION "NORWEGIANNYNORSK" "nn"
  !insertmacro SELECT_TRANSLATION_SECTION "ITALIAN" "it"
  !insertmacro SELECT_TRANSLATION_SECTION "SLOVENIAN" "sl"
  !insertmacro SELECT_TRANSLATION_SECTION "ESTONIAN" "et"
  !insertmacro SELECT_TRANSLATION_SECTION "RUSSIAN" "ru"
  !insertmacro SELECT_TRANSLATION_SECTION "KURDISH" "ku"
  !insertmacro SELECT_TRANSLATION_SECTION "HUNGARIAN" "hu"
  !insertmacro SELECT_TRANSLATION_SECTION "SPANISH" "es"
  !insertmacro SELECT_TRANSLATION_SECTION "LITHUANIAN" "lt"
  !insertmacro SELECT_TRANSLATION_SECTION "SLOVAK" "sk"
  !insertmacro SELECT_TRANSLATION_SECTION "ROMANIAN" "ro"
  !insertmacro SELECT_TRANSLATION_SECTION "AFRIKAANS" "af"
  !insertmacro SELECT_TRANSLATION_SECTION "SIMPCHINESE" "zh_CN"
  !insertmacro SELECT_TRANSLATION_SECTION "SWEDISH" "sv"
  !insertmacro SELECT_TRANSLATION_SECTION "IRISH" "ga"
  !insertmacro SELECT_TRANSLATION_SECTION "DUTCH" "nl"
  !insertmacro SELECT_TRANSLATION_SECTION "ARABIC" "ar"
  !insertmacro SELECT_TRANSLATION_SECTION "FRENCH" "fr"
  !insertmacro SELECT_TRANSLATION_SECTION "ALBANIAN" "sq"
  !insertmacro SELECT_TRANSLATION_SECTION "JAPANESE" "ja"
  !insertmacro SELECT_TRANSLATION_SECTION "POLISH" "pl"
  !insertmacro SELECT_TRANSLATION_SECTION "DANISH" "da"
  !insertmacro SELECT_TRANSLATION_SECTION "HEBREW" "he"
  !insertmacro SELECT_TRANSLATION_SECTION "GREEK" "el"
  !insertmacro SELECT_TRANSLATION_SECTION "GERMAN" "de"
  !insertmacro SELECT_TRANSLATION_SECTION "PORTUGUESE" "pt"
  !insertmacro SELECT_TRANSLATION_SECTION "CATALAN" "ca"
  !insertmacro SELECT_TRANSLATION_SECTION "CZECH" "cs"
  !insertmacro SELECT_TRANSLATION_SECTION "NORWEGIAN" "nb"
  !insertmacro SELECT_TRANSLATION_SECTION "TRADCHINESE" "zh_TW"
  !insertmacro SELECT_TRANSLATION_SECTION "FINNISH" "fi"

done:
!macroend
