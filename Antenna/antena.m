function main
    data = readmatrix("anteny1.csv");
    deegree = data(:, 1);   
    intencity = data(:, 2:end); 

    polarPlotData(intencity, deegree, 0, false);
    plotData(intencity, deegree, 0, false);
    polarPlotData(intencity, deegree, 0, true);
    plotData(intencity, deegree, 0, true);

    for i = 1:size(intencity, 2)
        polarPlotData(intencity(:, i), deegree, i, true);
        plotData(intencity(:, i), deegree, i, true);
    end
end

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
    figure;
    pax = polaraxes;
    hold(pax, 'on');
    if isNormalised
        set(pax, 'ThetaZeroLocation', 'top');
    end

    if size(r, 2) == 1
        r = r(:);
    end

    colors = lines(size(r, 2));

    for i = 1:size(r, 2)
        r_i = r(:, i);
        [~, idx_max] = max(r_i);

        theta_i = theta;
        if isNormalised
            theta_max = theta_i(idx_max);
            theta_i = theta_i - theta_max;
        end

        [theta_sorted, idx_sorted] = sort(theta_i);
        r_sorted = r_i(idx_sorted);
        r_sorted = r_sorted / max(r_sorted);
        theta_rad = deg2rad(theta_sorted);

        polarplot(pax, theta_rad, r_sorted, 'LineWidth', 1.5, 'Color', colors(i, :));

        halfPower = find3dB(idx_max, r_sorted);

        if ~isNormalised
            theta_line = deg2rad([theta_sorted(idx_max), theta_sorted(idx_max)]);
            polarplot(pax, theta_line, [0 1], 'r-', 'LineWidth', 1.2);
        end

        polarplot(pax, deg2rad([theta_sorted(halfPower(1)), theta_sorted(halfPower(1))]), [0, 1], 'b-', 'LineWidth', 1.2);
        polarplot(pax, deg2rad([theta_sorted(halfPower(2)), theta_sorted(halfPower(2))]), [0, 1], 'b-', 'LineWidth', 1.2);

        archdeg = theta_sorted(halfPower(1)):0.5:theta_sorted(halfPower(2));
        archpoints = 0.707 * ones(size(archdeg));
        polarplot(pax, deg2rad(archdeg), archpoints, 'b-', 'LineWidth', 1.2);

        alpha = deg2rad((theta_sorted(halfPower(2)) + theta_sorted(halfPower(1))) / 2);

        text(0.8*cos(alpha), 0.8*sin(-alpha), ...
            sprintf('$\\alpha_{0{,}707}^{(%d)} = %d^{\\circ}$', i, round(abs(theta_sorted(halfPower(2)) - theta_sorted(halfPower(1))))), ...
            'Color', colors(i, :), 'Interpreter', 'latex', ...
            'HorizontalAlignment', 'center', 'VerticalAlignment', 'top', 'FontSize', 12);

        text(deg2rad(theta_sorted(idx_max)), 1, ...
            sprintf('$I_{max}^{(%d)} = %d^{\\circ}$', i, round(theta_sorted(idx_max))), ...
            'Color', colors(i, :), 'Interpreter', 'latex', ...
            'HorizontalAlignment', 'left', 'VerticalAlignment', 'top', 'FontSize', 12);
    end

    title(pax, sprintf('Charakterystyka promieniowania we współrzędnych biegunowych - antena %d', num));
    rlim(pax, [0 1]);
    rticks(pax, [0.2 0.4 0.6 0.8 1.0]);
    hold(pax, 'off');
end

function plotData(r, theta, num, isNormalised)
    figure;
    hold on;
    colors = lines(size(r, 2));

    if size(r, 2) == 1
        r = r(:);
    end

    for i = 1:size(r, 2)
        r_i = r(:, i);
        [~, idx_max] = max(r_i);

        theta_i = theta;
        if isNormalised
            theta_max = theta_i(idx_max);
            theta_i = theta_i - theta_max;
        end

        [theta_sorted, idx_sorted] = sort(theta_i);
        r_sorted = r_i(idx_sorted);
        r_sorted = r_sorted / max(r_sorted);

        plot(theta_sorted, r_sorted, 'LineWidth', 1.5, 'Color', colors(i, :));

        halfPower = find3dB(idx_max, r_sorted);

        if isNormalised
            xticks(-150:30:270);
            xlim([-150, 270]);
        else
            xline(theta_sorted(idx_max), '-r');
        end

        x = (theta_sorted(halfPower(2)) - theta_sorted(halfPower(1))) / 2 + theta_sorted(halfPower(1));
        xline(theta_sorted(halfPower(1)), '-b');
        xline(theta_sorted(halfPower(2)), '-b');
        line([theta_sorted(halfPower(1)), theta_sorted(halfPower(2))], [0.707, 0.707], 'Color', 'blue');

        text(theta_sorted(idx_max), 0.8, ...
            sprintf('$I_{max}^{(%d)} = %d^{\\circ}$', i, round(theta_sorted(idx_max))), ...
            'Interpreter', 'latex', 'Color', colors(i, :), ...
            'HorizontalAlignment', 'right', 'VerticalAlignment', 'bottom', 'FontSize', 12);

        text(x, 0.7, ...
            sprintf('$\\alpha_{0{,}707}^{(%d)} = %d^{\\circ}$', i, round(abs(theta_sorted(halfPower(2)) - theta_sorted(halfPower(1))))), ...
            'Color', 'blue', 'Interpreter', 'latex', ...
            'HorizontalAlignment', 'center', 'VerticalAlignment', 'top', 'FontSize', 12);
    end

    title(sprintf('Charakterystyka promieniowania we współrzędnych prostokątnych - antena %d', num));
    ylim([0 1]);
    xlabel('Kąt [°]');
    ylabel('$\frac{I}{I_{max}} \left[\frac{A}{A}\right]$', 'Interpreter', 'latex');
    hold off;
end
main();