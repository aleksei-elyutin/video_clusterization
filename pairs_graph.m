% ������������� ������ ������*****************************************
inputVideoName = 'D:\108ANV01\MAQ09013.mp4';
videoReader = VideoReader(inputVideoName);

features = struct('descriptor', [], 'keypoint', []);
matched_features = struct('descriptor', [], 'keypoint', []);


for i = 1 : 10%videoReader.NumberOfFrames
    frame=rgb2gray(read(videoReader,i));
    imshow (rgb2gray(read(videoReader,i))); hold on; 
    fps = detectSURFFeatures(frame,'MetricThreshold',1500);
    [dsc, validPoints] = extractFeatures(frame, fps, 'SURFSize',64);
    if i == 1
        features(i).keypoint = validPoints;
        features(i).descriptor = dsc;    
    else
    
        indexPairs = matchFeatures(dsc,features(i-1).descriptor,'Method',...
             'NearestNeighborSymmetric') ;
        features(i).keypoint = validPoints(indexPairs(:, 1));
        features(i).descriptor = dsc(indexPairs(:, 1),:);            
        
        features(i-1).keypoint = features(i-1).keypoint(indexPairs(:, 2));
        features(i-1).descriptor = features(i-1).descriptor(indexPairs(:, 2),:);
       
        for j=2:i            
            for k = 1:length(features(j).keypoint)    
              plot ([features(j-1).keypoint.Location(k,1), features(j).keypoint.Location(k,1)],...
              [features(j-1).keypoint.Location(k,2), features(j).keypoint.Location(k,2)]);
             end;
        end;
         pause(0.5);
    end;   
    disp (['Detecting progress: frame ' num2str(i) ' from ' num2str(videoReader.NumberOfFrames) ' ...']);
    disp (['Number of matched keypoints = ' num2str(length(features(i).keypoint))]);

end;
numMatches = [];

for i = 2 : 10%videoReader.NumberOfFrames
    numMatches(i-1) = length(features(i).keypoint);
    disp (['Matching progress: frame ' num2str(i) ' from ' num2str(videoReader.NumberOfFrames) '...']);
end;