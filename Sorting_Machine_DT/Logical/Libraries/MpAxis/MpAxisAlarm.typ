
TYPE
    MpAxisBasicAlarmEnum : 
        ( (* Alarms of MpAxis Basic *)
        mpAXIS_ALM_GENERAL_DRIVE_ERROR := 0, (* General drive error (+ ErrorCode as add. Info) *)
        mpAXIS_ALM_INITIALIZATION := 1, (* Error during initialization phase (+ ErrorCode as add. Info) *)
        mpAXIS_ALM_PARAMETERS_INVALID := 2, (* Input parameters invalid *)
        mpAXIS_ALM_MOTOR_OVERTEMP := 3, (* Motor overtemperature (+ acutal temp and "predictive" as add. Info "100.3, predictive" or "100.3") *)
        mpAXIS_ALM_LAG_ERROR := 4, (* Lag error *)
        mpAXIS_ALM_LIMIT_SWITCH_REACHED := 5, (* Positive or negative limit switch reached (+ direction&ErrorCode as add.Info: "pos, 12342") *)
        mpAXIS_ALM_DRIVE_ENABLE_LOW := 6, (* Voltage sage on the drive enable input *)
        mpAXIS_ALM_ENCODER := 7, (* Error on the encoder happened (signal amplitude, …) (+ ErrorCode as add. Info "5019") *)
        mpAXIS_ALM_MAIN_VOLTAGE := 8, (* Main voltage problem: DC bus volltage drop, over voltage, over current (+ ErrorCode as add. Info) *)
        mpAXIS_ALM_SAFETY := 9, (* Safety related error (+ ErrorCode as add. Info) *)
        mpAXIS_ALM_HOLDING_BRAKE := 10, (* Problem with holding brake (+ ErrorCode as add. Info) *)
        mpAXIS_ALM_NO_COMMUNICATION := 11, (* Communication (powerlink) breakdown, cable unplugged or defective (+ ErrorCode as add. Info) *)
        mpAXIS_ALM_DRIVE_OVERLOAD := 12, (* Overload on drive (e.g. IGBT overtemperature) (+ ErrorCode as add. Info) *)
        mpAXIS_ALM_MOTOR_OVERLOAD := 13, (* Overload on motor (e.g. peak current) (+ ErrorCode as add. Info) *)
        mpAXIS_ALM_GENERAL_WARNING := 14, (* General drive warning (+ WarningCode as add. Info) *)
        mpAXIS_ALM_TORQUE_LIMIT_REACHED := 15 (* Torque reached the limit configured (+ Torque reached as add. Info) *)
    );
END_TYPE
