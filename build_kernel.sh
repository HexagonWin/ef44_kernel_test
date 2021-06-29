#!/bin/bash
########################################################################
#                            EasyKBUILD 3.1                            #
#                                                                      #
#              By Pantech Wiress, modified by HexagonWin               #
#       This program is free software, licensed under GNU GPL V3       #
#======================================================================#
# I. Changelogs                                                        #
#                                                                      #
# 2010 / 12 / 29 : allydrop   -   created                              #
# 2011 / 10 / 24 : effectivesky - modified                             #
# 2021 / 06 / 14 : hexagonwin  -  create custom defconfig mode         #
# 2021 / 06 / 28 : hexagonwin  -  almost a complete rewrite            #
# 2021 / 06 / 29 : hexagonwin  -  add changelogs from previous vers    #
#======================================================================#
#                                                                      #
# II. Settings //Modify to fit your needs                              #
#                                                                      #
  export ARCH=arm #Architecture.
  export CROSS_COMPILE=~/arm-eabi-4.8/bin/arm-eabi- #Toolchain.
  export EZKBUILD_OUTPUT=ezout #Output folder.
  export EZKBUILD_JOBS=10 #How many j option.

  export EZKBUILD_VER=3.1 #EasyKBUILD version. Don't edit
#======================================================================#
#                                                                      #
# III. Logs display //Do not edit                                      #
#                                                                      #
  echo "EasyKBuild $EZKBUILD_VER script started."                      #
  echo "Architecture set to '$ARCH'"                                   #
  echo "Toolchain set to '$CROSS_COMPILE'"                             #
  echo "Output directory set to '$EZKBUILD_OUTPUT'"                    #
  echo "Defconfig set to '$1'"                                         #
  echo "Building with jobs option j=$EZKBUILD_JOBS"                    #
#======================================================================#
#                                                                      #
# IV. Kernel build //Edit if needed                                    #
#                                                                      #
  mkdir -p ./$EZKBUILD_OUTPUT/
  make O=./$EZKBUILD_OUTPUT/ $1
  make -j$EZKBUILD_JOBS O=./$EZKBUILD_OUTPUT/

  echo "EasyKBuild $EZKBUILD_VER script finished."
########################################################################
