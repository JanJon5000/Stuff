function a = find3dB(startTheta, matrixToSearch)

    for i = startTheta+1:1:numel(matrixToSearch)
        if matrixToSearch(i) < 0.707
            a = i;
            break;
        end
    end
    for i = startTheta-1:-1:1
        if matrixToSearch(i) < 0.707
            a = [i, a];
            return;
        end
    end
end

function polarPlotData(r, theta, num, isNormalised)         
    [~, idx_max] = max(r);

    if isNormalised
        theta_max = theta(idx_max);
        theta = theta - theta_max;
    end

    [theta_sorted, idx_sorted] = sort(theta);
    r_sorted = r(idx_sorted);
    r_sorted = r_sorted / max(r_sorted);  
    theta_rad = deg2rad(theta_sorted);

    figure;
    polarplot(theta_rad, r_sorted, 'LineWidth', 1.5);
    hold on;
    halfPower = find3dB(idx_max, r_sorted);
    if isNormalised == false
        theta_line = deg2rad([theta_sorted(idx_max), theta_sorted(idx_max)]);
        r_line = [0 1];
        polarplot(theta_line, r_line, 'r-', 'LineWidth', 1.2);
        text(theta_sorted(idx_max), 1, sprintf('kąt Imax %d', theta_sorted(idx_max)), 'Color', 'red', 'HorizontalAlignment', 'left', 'VerticalAlignment', 'top', 'FontSize', 8);
    end
    polarplot(deg2rad([theta_sorted(halfPower(1)), theta_sorted(halfPower(1))]), [0, 1], 'b-', 'LineWidth', 1.2);
    polarplot(deg2rad([theta_sorted(halfPower(2)), theta_sorted(halfPower(2))]), [0, 1], 'b-', 'LineWidth', 1.2);
    archdeg = theta_sorted(halfPower(1)):0.1:theta_sorted(halfPower(2));
    archpoints = 0.707 * ones(size(archdeg));
    polarplot(deg2rad(archdeg), archpoints, 'b-', 'LineWidth', 1.2);
    
    title(sprintf('Charakterystyka promieniowania we współrzędnych biegunowych - antena %d', num));
    rlim([0 1]);
    rticks([0.2 0.4 0.6 0.8 1.0]);
    hold off;
end


function plotData(r, theta, num, isNormalised) 
    [~, idx_max] = max(r);
    if isNormalised
        theta_max = theta(idx_max);
        theta = theta - theta_max;
    end

    [theta_sorted, idx_sorted] = sort(theta);
    r_sorted = r(idx_sorted);
    r_sorted = r_sorted / max(r_sorted); 

    figure;
    plot(theta_sorted, r_sorted, 'LineWidth', 1.5);
    title(sprintf('charakterystyka promieniowania we współrzędnych prostokątnych - antena %d', num));
    ylim([0 1]);
    xlabel('Kąt [°]');
    ylabel('I/Imax [A/A]');
    if isNormalised
        xticks(-180:30:300);
        xlim([-180, 300]);
    else
        xline(theta_sorted(idx_max), '-r', sprintf('Imax dla %d stopni', theta_sorted(idx_max)));
        xticks(0:30:360);
        xlim([0,360]);
    end
end

data = readmatrix("anteny1.csv");
deegree = data(:, 1);   
intencity = data(:, 2:end); 

for i = 1:size(intencity, 2)
    polarPlotData(intencity(:, i), deegree, i, false);
    plotData(intencity(:, i), deegree, i, false);
end
