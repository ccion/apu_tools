;-------------------------------------------------------------------------------
; Startup file for APEX
;-------------------------------------------------------------------------------

;-------------------------------------------------------------------------------
; Used when LLVM's source-based code coverage feature is enabled
;-------------------------------------------------------------------------------
    .text
    .file     "startup_lprof.s"

;-------------------------------------------------------------------------------
; Function __main_fsl
;-------------------------------------------------------------------------------
    .section  .text.__main_fsl, "ax"
    .weak     __main_fsl
    .align    2
    .type     __main_fsl,@function
__main_fsl:
    ori r30, r0, #_sp_start_value_VMb
    jal #lprofSetupValueProfiler
    orli r31, r0, #_sp_start_value_DMb         ; delay slot 1
    jal #__llvm_profile_initialize_file
    nop					       ; delay slot 1
    jal #main                        ; CMPAPEX-767 - Work around for
                                     ; unbalanced call/return error
                                     ; from synopsys simulator
    ori r29, r0, #__exit_fsl         ; delay slot 1
$__main_fsl__end:
    .size     __main_fsl, ($__main_fsl__end)-__main_fsl

;-------------------------------------------------------------------------------
; Function __exit_fsl
;-------------------------------------------------------------------------------
    .section  .text.__exit_fsl, "ax"
    .weak     __exit_fsl
    .align    2
    .type     __exit_fsl,@function
__exit_fsl:
    orli r2, r0, #stdout
    jal #fflush
    lw r2, 0(r2)                     ; delay slot 1
    jal #__llvm_profile_write_file
    nop                              ; delay slot 1
.end_of_main
$__exit_fsl__end:
    .size    __exit_fsl, ($__exit_fsl__end)-__exit_fsl

;-------------------------------------------------------------------------------
; External functions
;-------------------------------------------------------------------------------
    .type    main,@function
    .type    fflush,@function
    .type    lprofSetupValueProfiler,@function
    .type    __llvm_profile_write_file,@function
    .type    __llvm_profile_initialize_file,@function
