-- Script educacional para Arceus X
-- Coloque este script no executor durante o jogo

-- Proteção contra múltiplas execuções
if getgenv().autoClickRunning then return end
getgenv().autoClickRunning = true

-- Variáveis
local autoClick = false
local Players = game:GetService("Players")
local player = Players.LocalPlayer
local replicatedStorage = game:GetService("ReplicatedStorage")
local clickEvent = replicatedStorage:FindFirstChild("Click") -- Verifique o nome real do evento

-- Criar GUI
local screenGui = Instance.new("ScreenGui")
screenGui.Parent = player:WaitForChild("PlayerGui")
screenGui.Name = "ArceusXAutoClickGUI"

local button = Instance.new("TextButton")
button.Size = UDim2.new(0, 160, 0, 40)
button.Position = UDim2.new(0, 10, 0, 150)
button.BackgroundColor3 = Color3.fromRGB(0, 170, 255)
button.TextColor3 = Color3.new(1, 1, 1)
button.Font = Enum.Font.SourceSansBold
button.TextSize = 18
button.Text = "Ativar Auto Click"
button.Parent = screenGui
button.Active = true
button.Draggable = true -- Arceus X normalmente permite isso

-- Alternar o auto click
button.MouseButton1Click:Connect(function()
    autoClick = not autoClick
    if autoClick then
        button.Text = "Desativar Auto Click"
        button.BackgroundColor3 = Color3.fromRGB(0, 255, 127)
    else
        button.Text = "Ativar Auto Click"
        button.BackgroundColor3 = Color3.fromRGB(0, 170, 255)
    end
end)

-- Loop de Auto Click
spawn(function()
    while getgenv().autoClickRunning do
        if autoClick and clickEvent then
            pcall(function()
                clickEvent:FireServer()
            end)
        end
        wait(0.1) -- Intervalo entre cliques (pode ajustar)
    end
end)
