#!/bin/bash
# Copyright (c) 2016 Deepin Ltd. All rights reserved.
# Use of this source is governed by General Public License that can be found
# in the LICENSE file.

# Update default settings of desktop environment.
readonly SCHEMA_FILE=/usr/share/glib-2.0/schemas/99_deepin_installer_settings.gschema.override

LAUNCHER_HOLD_PKGS=$(installer_get "dde_launcher_hold_packages")
LAUNCHER_APPS=$(installer_get "dde_launcher_app_list")
if [ -n "${LAUNCHER_HOLD_PKGS}" ] || [ -n "${LAUNCHER_APPS}" ]; then
  echo "[com.deepin.dde.launcher]" >> "${SCHEMA_FILE}"
  if [ -n "${LAUNCHER_HOLD_PKGS}" ]; then
    echo "apps-hold-list=[${LAUNCHER_HOLD_PKGS}]" >> "${SCHEMA_FILE}"
  fi
  if [ -n "${LAUNCHER_APPS}" ]; then
    echo "apps-order=[${LAUNCHER_APPS}]" >> "${SCHEMA_FILE}"
  fi
fi

DOCK_APPS=$(installer_get "dde_dock_app_list")
if [ -n "${DOCK_APPS}" ]; then
  echo "[com.deepin.dde.dock]" >> "${SCHEMA_FILE}"
  echo "docked-apps=[${DOCK_APPS}]" >> "${SCHEMA_FILE}"
fi

SOUND_EFFECT=$(installer_get "dde_sound_effect_switches")
if [ -n "${SOUND_EFFECT}" ]; then
  echo "[com.deepin.dde.sound-effect]" >> "${SCHEMA_FILE}"
  SOUND_EFFECT_ARR=(${SOUND_EFFECT//;/ })
  for SOUND_EFFECT_ITEM in $(echo "${SOUND_EFFECT_ARR}"); do
    msg "sound effect: ${SOUND_EFFECT_ITEM}"
    echo "${SOUND_EFFECT_ITEM}" >> "${SCHEMA_FILE}"
  done
fi

msg "installer override schema file:"
[ -f "${SCHEMA_FILE}" ] && cat "${SCHEMA_FILE}"

return 0