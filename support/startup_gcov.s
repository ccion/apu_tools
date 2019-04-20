;-------------------------------------------------------------------------------
; Startup file for APEX
;-------------------------------------------------------------------------------

;-------------------------------------------------------------------------------
; Used when LLVM's GCC-compatible source based coverage
; implementation feature is enabled
;-------------------------------------------------------------------------------
    .text
    .file     "startup_gcov.s"

;-------------------------------------------------------------------------------
; Function __main_fsl
;-------------------------------------------------------------------------------
    .section  .text.__main_fsl, "ax"
    .weak     __main_fsl
    .align    2
    .type     __main_fsl,@function
__main_fsl:
    ori r30, r0, #_sp_start_value_VMb
    jal #__init_cpp
    orli r31, r0, #_sp_start_value_DMb
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
    jal #__fini_cpp
    nop                                ; delay slot 1
    jal #llvm_writeout_files
    nop                                ; delay slot 1
    jal #llvm_delete_writeout_function_list
    nop                                ; delay slot 1
    jal #llvm_delete_flush_function_list
    nop                                ; delay slot 1
    jal #__gcov_flush
    nop                                ; delay slot 1
    orli r2, r0, #stdout
    jal #fflush
    lw r2, 0(r2)                       ; delay slot 1
.end_of_main
$__exit_fsl__end:
    .size    __exit_fsl, ($__exit_fsl__end)-__exit_fsl

;-------------------------------------------------------------------------------
; External functions
;-------------------------------------------------------------------------------
    .type    main,@function
    .type    fflush,@function
    .type    __gcov_flush,@function
    .type    llvm_writeout_files,@function
    .type    llvm_delete_flush_function_list,@function
    .type    llvm_delete_writeout_function_list,@function
