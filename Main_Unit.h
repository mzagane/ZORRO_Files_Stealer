#ifndef Main_Unit_H
        #define Main_Unit_H

        //Variables
         AnsiString  Current_Dir, Target_Dir;//repertoire courant (où se trouve l'excutable), repertoire de destination
         AnsiString  User_Name, User_Dir, Bureau;
         TStringList * Config;
         AnsiString  Local_Disks, Removable_Disks, Cds;//disk to scan
         AnsiString  Enabled;// if =1 execution if =0 no execution
         AnsiString  Current_Drive;//

        //Functions
        void get_files(AnsiString src_directory, AnsiString des_directory, AnsiString files_type, bool get_sub_dir, bool system_dirs_files);
        AnsiString __fastcall GetUser();
        bool Load_Config(AnsiString Config_File_Name);// charger la configuration
        bool Not_My_Disk(AnsiString Drv);// to protect my Disks


#endif //Main_Unit_H
