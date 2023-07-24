% *************************************************************************
% * Lateral DMC X-Vector Parameters Tendency Check                        *
% *************************************************************************
% * Creators ............................................................ *
% ** Serghie, Andrei [uid38681]                                           *
% ** Pauca, Ovidiu [uidn2859]                                             *
% *************************************************************************
% * Description ......................................................... *
% ** This script shall be able to read the vectors from                   *
% ** paramlvc.c file and check the tendency of those vectors              *
% *************************************************************************

%% Initialiation

clc; % Clear the screen
clear
error = 0;

fid = fopen('LaDMC_X_Vectors_Tendency_Check_Report.doc','w');
fprintf(fid,'*------------------------------------------------------------------*\n');
fprintf(fid,'* Lateral DMC X-Vector Parameters Tendency Check \n');
fprintf(fid,'*------------------------------------------------------------------*\n\n');

% Put this to 1 to be able to debug this script
dmc_debug_activated = 0;

disp ('* Lateral DMC X-Vector Parameters Tendency Check');
disp ('********************************************************************');

%% Source file opening

disp ('* Opening the source file ...');

% Get the path where this script is stored
dmc_work_directory = pwd;

Working_Directory = [eval('cd'),'\'];                                   % Set the working directory
dmc_work_directory = [eval('cd'),'\'];
crnt_dir = pwd; 
crnt_dir = fileparts(crnt_dir);crnt_dir = fileparts(crnt_dir);
crnt_dir = fileparts(crnt_dir);crnt_dir = [fileparts(crnt_dir),'\Project_Specific'];
display('Please select the path containing the paramlvc.c file')
paramlvc_path = uigetdir(crnt_dir);
Src_File = 'paramlvc.c';                                                % The name of the source file

Src_File_Path = strcat(paramlvc_path,'\',Src_File);                     % Full path of the source file


% Open the paramlvc.c file in read mode
%[dmc_work_file.id, dmc_work_file.message] = fopen (strcat (dmc_work_directory, '\', 'paramlvc.c'), 'r');
[dmc_work_file.id, dmc_work_file.message] = fopen (strcat (paramlvc_path,'\',Src_File), 'r');


% Show status on Command Window regarding the file opening
if strcmp (dmc_work_file.message, 'No such file or directory') == 1
    disp ('** Error: No such file or directory!');
elseif strcmp (dmc_work_file.message, 'No such file or directory') ~= 1
    disp ('** The source file was successfully opened!');
end

disp ('* ------------------------------------------------------------------');

%% Data reading and formatting

disp ('* Reading and formatting the data from the source file ...');

% If the file is opened, create the arrays used for string replacement
if strcmp (dmc_work_file.message, 'No such file or directory') ~= 1
    dmc_arr.data_types = {'unsigned_char_t ', 'unsigned_int16_t ', 'signed_int16_t '};
    dmc_arr.vector_dimensions = {'[2]', '[3]', '[4]', '[5]', '[6]', '[7]', '[8]', '[9]', '[10]', '[11]', '[12]', '[13]', '[14]', '[15]'};
    dmc_arr.miscellaneous = {'@', '/*', '*/', ',', '#', '(', ')'};
end

if strcmp (dmc_work_file.message, 'No such file or directory') == 1
    
    % If the file is not opened, display an error message
    disp ('** Error: The data from the source file was not successfully read!'); error = error + 1;
    fprintf(fid,'** Error: The data from the source file was not successfully read!\n');
    
elseif strcmp (dmc_work_file.message, 'No such file or directory') ~= 1
    
    % Scan the paramlvc.c file
    dmc_work_file.data = textscan (dmc_work_file.id, '%s', 'delimiter', '\n', 'whitespace', '');
    
    % Convert the scanned data to one single cell
    dmc_work_file.data = dmc_work_file.data{1};
    
    % write the raw data to word file
    fprintf(fid,'** paramlvc.c File Content\n\n');
    for i = 1:size(dmc_work_file.data, 1)
        extract_line = dmc_work_file.data(i,:);
        fprintf(fid,'%s\n',extract_line{1});
    end    
    
    % Remove everything within comments
       
    lengthOfFile=length(dmc_work_file.data);
    commentsFound=1;
    while commentsFound    
    commentsFound=0; 
        for i = 1 : lengthOfFile     
           startCommFound = strfind(dmc_work_file.data{i},'/*');
           endofCommFound = strfind(dmc_work_file.data{i},'*/');

           if ~isempty(startCommFound)&&~isempty(endofCommFound)
             dmc_work_file.data{i}(startCommFound:endofCommFound+1) =[];
             commentsFound=1;        
           end                         
        end
    end  

    % Remove the miscellaneous symbols
    for i = 1 : length (dmc_arr.miscellaneous)
        dmc_work_file.data = strrep (dmc_work_file.data, char (dmc_arr.miscellaneous(i)), '');
    end
    
    % Remove the data types
    for i = 1 : length (dmc_arr.data_types)
        dmc_work_file.data = strrep (dmc_work_file.data, char (dmc_arr.data_types(i)), '');
    end
    
    % Back-up the data before removing the vector dimensions
    dmc_work_file.back_up = dmc_work_file.data;
    
    % Remove the vector dimensions
    for i = 1 : length (dmc_arr.vector_dimensions)
        dmc_work_file.back_up = strrep (dmc_work_file.back_up, char (dmc_arr.vector_dimensions(i)), '');
    end
    
    % Convert the scanned data and the back-up data to char
    dmc_work_file.data = char (dmc_work_file.data);
    dmc_work_file.back_up = char (dmc_work_file.back_up);
    
    % If everyting went fine until this point, display a status message
    disp ('** The data from the source file was succesfully read and formatted!');
    
end

disp ('* ------------------------------------------------------------------');

%% Source file closing

disp ('* Closing the source file ...');

if strcmp (dmc_work_file.message, 'No such file or directory') == 1
    
    % If the file is not opened, display an error message
    disp ('** Error: There is no file to close!'); error = error + 1;
    
elseif strcmp (dmc_work_file.message, 'No such file or directory') ~= 1
    
    % If the file is opened, close the file and display a status message
    dmc_work_file.close = fclose (dmc_work_file.id);
    disp ('** The source file was successfully closed!');
    
end

disp ('* ------------------------------------------------------------------');

%% Data extraction

disp ('* Extracting data ...');

% If the file is opened, compute the size of the scaned data
if strcmp (dmc_work_file.message, 'No such file or directory') ~= 1
    dmc_work_file.data_size = size (dmc_work_file.data);
end

if strcmp (dmc_work_file.message, 'No such file or directory') == 1
    
    % If the file is not opened, display an error message
    disp ('** Error: The data extraction failed!'); error = error + 1;
    
elseif strcmp (dmc_work_file.message, 'No such file or directory') ~= 1
    
    % Get the position of the X vector within the scanned data
    for i = 1 : dmc_work_file.data_size
        dmc_temp_string = dmc_work_file.data(i,:);
        dmc_string_position(i) = 0;
        for j = 1 : length (dmc_arr.vector_dimensions)
            if strfind (dmc_temp_string, char (dmc_arr.vector_dimensions(j))) ~= 0 & strfind (dmc_temp_string, '_X_') ~= 0 | strfind (dmc_temp_string, '_X[') ~= 0
                dmc_string_position(i) = i;
            end
        end
    end

    % Use a static index to copy relevant only data
    dmc_static_index = 1;

    % Extract the relevant data only from the back-up data
    for i = 1 : dmc_work_file.data_size
        if dmc_string_position(i) ~= 0
            dmc_extracted_data(dmc_static_index,:) = regexprep (lower (dmc_work_file.back_up(i,:)), '(\<[a-z])', '${upper($1)}');
            dmc_extracted_data(dmc_static_index + 1,:) = dmc_work_file.back_up(i + 1,:);
            dmc_extracted_data(dmc_static_index + 2,:) = dmc_work_file.back_up(i + 2,:);
            dmc_extracted_data(dmc_static_index + 3,:) = dmc_work_file.back_up(i + 3,:);
            dmc_extracted_data(dmc_static_index + 4,:) = dmc_work_file.back_up(i + 4,:);
            dmc_static_index = dmc_static_index + 5;
        end
    end
    
    % If everyting went fine until this point, display a status message
    disp ('** The data was successfully extracted!');
end

disp ('* ------------------------------------------------------------------');

%% Temporary data storing and clearing workspace

disp ('* Storing data in a temporary file ...');

% Create the dmc_temp.m file to store the extracted data
[dmc_temp_file.id, dmc_temp_file.message] = fopen (strcat (dmc_work_directory, '\', 'dmc_temp.m'), 'w');
dmc_temp_file.full_path = strcat (dmc_work_directory, '\', 'dmc_temp_file.m');

if strcmp (dmc_work_file.message, 'No such file or directory') == 1
    
    % If the file is not opened, display an error message
    disp ('** Error: The data storing failed!'); error = error + 1;
    
elseif strcmp (dmc_work_file.message, 'No such file or directory') ~= 1
    
    % Compute the size of the extracted data
    dmc_extracted_data_size = size (dmc_extracted_data);
    
    % Copy the relevant extracted data to the dmc_temp.m file
    for i = 1 : 5 : dmc_extracted_data_size(1)
        dmc_temp_string = strcat ('DMC_VECTORS.', dmc_extracted_data(i,:), ' single', ' ([', dmc_extracted_data(i + 2,:), ' ])',';');
        fprintf (dmc_temp_file.id, '%s\n', dmc_temp_string); 
    end

    % If everyting went fine until this point, display a status message
    disp ('** The data was successfully stored!');
    
end

% If the file is opened, clear the workspace, close and run the dmc_temp.m file
if strcmp (dmc_work_file.message, 'No such file or directory') ~= 1
    dmc_temp_file.close = fclose (dmc_temp_file.id);
    if dmc_debug_activated == 0
		clear ans dmc_arr dmc_extracted_data dmc_extracted_data_size ...
    	dmc_static_index dmc_string_position dmc_temp_complete dmc_temp_name ...
    	dmc_temp_string dmc_temp_values i j
	end
    run dmc_temp;
end

% Clear the workspace
if dmc_debug_activated == 0
	clear dmc_work_file dmc_temp_file dmc_work_directory
end

disp ('* ------------------------------------------------------------------');

%% Tendency checking

disp ('* Checking the tendency of X vectors ...');

% Check if the DMC_VECTORS structure exists
exist DMC_VECTORS;

fprintf(fid,'\n*------------------------------------------------------------------*\n');
fprintf(fid,'** Check Result');
fprintf(fid,'\n*------------------------------------------------------------------*\n\n');

if ans == 0
    
    % If the DMC_VECTORS structure does not exist, display an error message
    disp ('** Error: There are no vectors to be checked!'); error = error + 1;
    fprintf(fid,'** Error: There are no vectors to be checked!\n');
    
else
    
    % Extract the names and the values from DMC_VECTORS structure
    dmc_vectors_names = fieldnames (DMC_VECTORS);
    dmc_vectors_values = struct2cell (DMC_VECTORS);

    for i = 1 : length (dmc_vectors_names)

        % Get only one vector at a time
        dmc_checked_vector = dmc_vectors_values{i};

        % Sort the vector
        dmc_checked_vector_asc_sorted = sort (dmc_checked_vector, 'ascend');
        dmc_checked_vector_des_sorted = sort (dmc_checked_vector, 'descend');

        % Check if the vector is sorted
        dmc_is_sorted = sum (dmc_checked_vector == dmc_checked_vector_asc_sorted) == length (dmc_checked_vector) ...
            || sum (dmc_checked_vector == dmc_checked_vector_des_sorted) == length (dmc_checked_vector);

        % Check if the vector is not monotonical
        if dmc_is_sorted == 1
            
            dmc_vector_element = 0;
            dmc_vector_is_ok = 1;
            for j = 1 : length (dmc_checked_vector)
                dmc_vector_element = dmc_checked_vector(dmc_checked_vector == dmc_checked_vector(j));
                if length (dmc_vector_element) == 1
                    dmc_vector_element = 0;
                    dmc_vector_is_ok = dmc_vector_is_ok * 1;
                else
                    dmc_vector_is_ok = dmc_vector_is_ok * 0;
                    j = length (dmc_checked_vector) + 1;
                end
            end

            if dmc_vector_is_ok == 1
                
                % If the vector is ok, display a status message
                if i >= 10
                    disp (strcat (num2str(i), '.', dmc_vectors_names{i}, ' | Status: OK!'));
                    fprintf(fid,'%s.%s | Status: OK!\n',num2str(i), dmc_vectors_names{i});
                else
                    disp (strcat ('0', num2str(i), '.', dmc_vectors_names{i}, ' | Status: OK!'));
                    fprintf(fid,'0%s.%s | Status: OK!\n', num2str(i), dmc_vectors_names{i});
                end
            else
                error = error + 1;
                % If the vector is not ok, display an error message
                if i >= 10
                    disp (strcat (num2str(i), '.', dmc_vectors_names{i}, ' | Status: NOK! Please check!'));
                    fprintf(fid,'%s.%s | Status: NOK! Please check!\n',num2str(i), dmc_vectors_names{i});
                else
                    disp (strcat ('0', num2str(i), '.', dmc_vectors_names{i}, ' | Status: NOK! Please check!'));
                    fprintf(fid,'0%s.%s | Status: NOK! Please check!\n',num2str(i), dmc_vectors_names{i});
                end
                
            end
            
        else
            error = error + 1;
            % If the vector is not ok, display an error message
            if i >= 10
                disp (strcat (num2str(i), '.', dmc_vectors_names{i}, ' | Status: NOK! Please check!'));
                fprintf(fid,'%s.%s | Status: NOK! Please check!\n',num2str(i), dmc_vectors_names{i});
            else
                disp (strcat ('0', num2str(i), '.', dmc_vectors_names{i}, ' | Status: NOK! Please check!'));
                fprintf(fid,'0%s.%s | Status: NOK! Please check!\n',num2str(i), dmc_vectors_names{i});
            end
            
        end
    end

    % If everyting went fine until this point, display a status message
    disp ('** All X vectors were checked!');
    
    % Clear the workspace
    if dmc_debug_activated == 0
        clear ans dmc_checked_vector dmc_checked_vector_asc_sorted dmc_checked_vector_des_sorted ...
        dmc_is_sorted dmc_vector_element dmc_vector_is_ok dmc_vectors_names dmc_vectors_values i j
	end
    
end

disp ('********************************************************************');
fprintf(fid,'\n*------------------------------------------------------------------*\n');
if (error > 0)
    disp( [num2str(error), ' error(s) found !!!']);
 fprintf(fid,( [num2str(error), ' error(s) found !!!']));
else
    disp( 'No errors found.');
 fprintf(fid, 'No errors found.');
end;
fprintf(fid,'\n*------------------------------------------------------------------*');
fclose(fid);
