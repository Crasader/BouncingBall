<GameProjectFile>
  <PropertyGroup Type="Scene" Name="Title_0" ID="ee94d92a-9b5e-45f1-987d-ec2a79d9ac85" Version="2.2.8.0" />
  <Content ctype="GameProjectContent">
    <Content>
      <Animation Duration="0" Speed="1.0000" />
      <ObjectData Name="Scene" Tag="313" ctype="GameNodeObjectData">
        <Size X="640.0000" Y="1136.0000" />
        <Children>
          <AbstractNodeData Name="BackGround_1" ActionTag="96750181" Tag="314" IconVisible="False" PositionPercentXEnabled="True" PositionPercentYEnabled="True" LeftMargin="-15.0000" RightMargin="-15.0000" TopMargin="-26.5000" BottomMargin="-26.5000" ctype="SpriteObjectData">
            <Size X="670.0000" Y="1189.0000" />
            <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
            <Position X="320.0000" Y="568.0000" />
            <Scale ScaleX="1.0000" ScaleY="1.0000" />
            <CColor A="255" R="255" G="255" B="255" />
            <PrePosition X="0.5000" Y="0.5000" />
            <PreSize X="1.0469" Y="1.0467" />
            <FileData Type="Normal" Path="asset/BackGround.png" Plist="" />
            <BlendFunc Src="1" Dst="771" />
          </AbstractNodeData>
          <AbstractNodeData Name="bottomBound_2" ActionTag="358643378" Tag="315" IconVisible="False" PositionPercentXEnabled="True" PositionPercentYEnabled="True" LeftMargin="-64.0000" RightMargin="-64.0000" TopMargin="863.0000" ctype="SpriteObjectData">
            <Size X="768.0000" Y="273.0000" />
            <AnchorPoint ScaleX="0.5000" />
            <Position X="320.0000" />
            <Scale ScaleX="1.0000" ScaleY="1.0000" />
            <CColor A="255" R="255" G="255" B="255" />
            <PrePosition X="0.5000" />
            <PreSize X="1.2000" Y="0.2403" />
            <FileData Type="Normal" Path="asset/bottomBound.png" Plist="" />
            <BlendFunc Src="1" Dst="771" />
          </AbstractNodeData>
          <AbstractNodeData Name="BitmapFontLabel_1" ActionTag="-1257627559" Tag="326" IconVisible="False" LeftMargin="87.6365" RightMargin="74.3635" TopMargin="233.4212" BottomMargin="819.5788" LabelText="Bouncing Ball" ctype="TextBMFontObjectData">
            <Size X="478.0000" Y="83.0000" />
            <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
            <Position X="326.6365" Y="861.0788" />
            <Scale ScaleX="1.2000" ScaleY="1.2000" />
            <CColor A="255" R="255" G="255" B="255" />
            <PrePosition X="0.5104" Y="0.7580" />
            <PreSize X="0.7719" Y="0.0731" />
            <LabelBMFontFile_CNB Type="Normal" Path="font01.fnt" Plist="" />
          </AbstractNodeData>
          <AbstractNodeData Name="singlePlayButton" ActionTag="1143013639" Tag="338" IconVisible="False" LeftMargin="65.3054" RightMargin="394.6946" TopMargin="385.5065" BottomMargin="573.4935" TouchEnable="True" FontSize="14" Scale9Enable="True" LeftEage="15" RightEage="15" TopEage="11" BottomEage="11" Scale9OriginX="15" Scale9OriginY="11" Scale9Width="150" Scale9Height="155" OutlineSize="1" ShadowOffsetX="2" ShadowOffsetY="-2" ctype="ButtonObjectData">
            <Size X="180.0000" Y="177.0000" />
            <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
            <Position X="155.3054" Y="661.9935" />
            <Scale ScaleX="1.8000" ScaleY="1.8000" />
            <CColor A="255" R="255" G="255" B="255" />
            <PrePosition X="0.2427" Y="0.5827" />
            <PreSize X="0.2813" Y="0.1558" />
            <TextColor A="255" R="65" G="65" B="70" />
            <DisabledFileData Type="Default" Path="Default/Button_Disable.png" Plist="" />
            <PressedFileData Type="Normal" Path="asset/singlePlayerButton.png" Plist="" />
            <NormalFileData Type="Normal" Path="asset/singlePlayerButton.png" Plist="" />
            <OutlineColor A="255" R="255" G="0" B="0" />
            <ShadowColor A="255" R="110" G="110" B="110" />
          </AbstractNodeData>
          <AbstractNodeData Name="multiplayButton" ActionTag="1251654902" Tag="372" IconVisible="False" LeftMargin="400.6199" RightMargin="59.3801" TopMargin="432.5152" BottomMargin="526.4848" TouchEnable="True" FontSize="14" Scale9Enable="True" LeftEage="15" RightEage="15" TopEage="11" BottomEage="11" Scale9OriginX="15" Scale9OriginY="11" Scale9Width="150" Scale9Height="155" OutlineSize="1" ShadowOffsetX="2" ShadowOffsetY="-2" ctype="ButtonObjectData">
            <Size X="180.0000" Y="177.0000" />
            <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
            <Position X="490.6199" Y="614.9848" />
            <Scale ScaleX="1.8000" ScaleY="1.8000" />
            <CColor A="255" R="255" G="255" B="255" />
            <PrePosition X="0.7666" Y="0.5414" />
            <PreSize X="0.2813" Y="0.1558" />
            <TextColor A="255" R="65" G="65" B="70" />
            <DisabledFileData Type="Default" Path="Default/Button_Disable.png" Plist="" />
            <PressedFileData Type="Normal" Path="asset/multiplayerButton.png" Plist="" />
            <NormalFileData Type="Normal" Path="asset/multiplayerButton.png" Plist="" />
            <OutlineColor A="255" R="255" G="0" B="0" />
            <ShadowColor A="255" R="110" G="110" B="110" />
          </AbstractNodeData>
          <AbstractNodeData Name="BitmapFontLabel_2" ActionTag="25840118" Tag="375" IconVisible="False" LeftMargin="47.5577" RightMargin="376.4423" TopMargin="420.7554" BottomMargin="632.2446" LabelText="Single" ctype="TextBMFontObjectData">
            <Size X="216.0000" Y="83.0000" />
            <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
            <Position X="155.5577" Y="673.7446" />
            <Scale ScaleX="0.7000" ScaleY="0.7000" />
            <CColor A="255" R="255" G="255" B="255" />
            <PrePosition X="0.2431" Y="0.5931" />
            <PreSize X="0.7719" Y="0.0731" />
            <LabelBMFontFile_CNB Type="Normal" Path="font01.fnt" Plist="" />
          </AbstractNodeData>
          <AbstractNodeData Name="BitmapFontLabel_2_0" ActionTag="-860969591" Tag="376" IconVisible="False" LeftMargin="397.1235" RightMargin="58.8765" TopMargin="470.7600" BottomMargin="582.2400" LabelText="Multi" ctype="TextBMFontObjectData">
            <Size X="184.0000" Y="83.0000" />
            <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
            <Position X="489.1235" Y="623.7400" />
            <Scale ScaleX="0.7000" ScaleY="0.7000" />
            <CColor A="255" R="255" G="255" B="255" />
            <PrePosition X="0.7643" Y="0.5491" />
            <PreSize X="0.7719" Y="0.0731" />
            <LabelBMFontFile_CNB Type="Normal" Path="font01.fnt" Plist="" />
          </AbstractNodeData>
          <AbstractNodeData Name="BitmapFontLabel_2_1" ActionTag="-331546418" Tag="377" IconVisible="False" LeftMargin="396.3699" RightMargin="53.6301" TopMargin="508.0189" BottomMargin="544.9811" LabelText="Mode" ctype="TextBMFontObjectData">
            <Size X="190.0000" Y="83.0000" />
            <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
            <Position X="491.3699" Y="586.4811" />
            <Scale ScaleX="0.7000" ScaleY="0.7000" />
            <CColor A="255" R="255" G="255" B="255" />
            <PrePosition X="0.7678" Y="0.5163" />
            <PreSize X="0.7719" Y="0.0731" />
            <LabelBMFontFile_CNB Type="Normal" Path="font01.fnt" Plist="" />
          </AbstractNodeData>
          <AbstractNodeData Name="BitmapFontLabel_2_1_0" ActionTag="-950556756" Tag="378" IconVisible="False" LeftMargin="62.0554" RightMargin="387.9446" TopMargin="461.2620" BottomMargin="591.7380" LabelText="Mode" ctype="TextBMFontObjectData">
            <Size X="190.0000" Y="83.0000" />
            <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
            <Position X="157.0554" Y="633.2380" />
            <Scale ScaleX="0.7000" ScaleY="0.7000" />
            <CColor A="255" R="255" G="255" B="255" />
            <PrePosition X="0.2454" Y="0.5574" />
            <PreSize X="0.7719" Y="0.0731" />
            <LabelBMFontFile_CNB Type="Normal" Path="font01.fnt" Plist="" />
          </AbstractNodeData>
          <AbstractNodeData Name="optionButton" ActionTag="-910506212" Tag="379" IconVisible="False" LeftMargin="192.4557" RightMargin="267.5443" TopMargin="621.0514" BottomMargin="337.9486" ctype="SpriteObjectData">
            <Size X="180.0000" Y="177.0000" />
            <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
            <Position X="282.4557" Y="426.4486" />
            <Scale ScaleX="1.8000" ScaleY="1.8000" />
            <CColor A="255" R="255" G="255" B="255" />
            <PrePosition X="0.4413" Y="0.3754" />
            <PreSize />
            <FileData Type="Normal" Path="asset/optionButton.png" Plist="" />
            <BlendFunc Src="1" Dst="771" />
          </AbstractNodeData>
          <AbstractNodeData Name="BitmapFontLabel_2_0_0" ActionTag="-2030067753" Tag="380" IconVisible="False" LeftMargin="161.9589" RightMargin="237.0411" TopMargin="671.5509" BottomMargin="381.4491" LabelText="Option" ctype="TextBMFontObjectData">
            <Size X="241.0000" Y="83.0000" />
            <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
            <Position X="282.4589" Y="422.9491" />
            <Scale ScaleX="0.7000" ScaleY="0.7000" />
            <CColor A="255" R="255" G="255" B="255" />
            <PrePosition X="0.4413" Y="0.3723" />
            <PreSize X="0.7719" Y="0.0731" />
            <LabelBMFontFile_CNB Type="Normal" Path="font01.fnt" Plist="" />
          </AbstractNodeData>
        </Children>
      </ObjectData>
    </Content>
  </Content>
</GameProjectFile>