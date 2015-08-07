<GameProjectFile>
  <PropertyGroup Type="Node" Name="Transport" ID="8bf3127b-cfed-41f1-bd52-720b3d5af748" Version="2.2.8.0" />
  <Content ctype="GameProjectContent">
    <Content>
      <Animation Duration="10" Speed="0.5000" ActivedAnimationName="transport">
        <Timeline ActionTag="539000274" Property="Position">
          <PointFrame FrameIndex="1" X="24.8020" Y="24.3669">
            <EasingData Type="0" />
          </PointFrame>
        </Timeline>
        <Timeline ActionTag="539000274" Property="Scale">
          <ScaleFrame FrameIndex="1" X="0.9000" Y="0.9000">
            <EasingData Type="0" />
          </ScaleFrame>
          <ScaleFrame FrameIndex="10" X="0.7500" Y="0.7500">
            <EasingData Type="0" />
          </ScaleFrame>
        </Timeline>
        <Timeline ActionTag="539000274" Property="RotationSkew">
          <ScaleFrame FrameIndex="1" X="0.0000" Y="0.0000">
            <EasingData Type="0" />
          </ScaleFrame>
        </Timeline>
        <Timeline ActionTag="2070003754" Property="Position">
          <PointFrame FrameIndex="3" X="24.5190" Y="64.5377">
            <EasingData Type="0" />
          </PointFrame>
        </Timeline>
        <Timeline ActionTag="2070003754" Property="Scale">
          <ScaleFrame FrameIndex="3" X="0.5000" Y="0.5000">
            <EasingData Type="0" />
          </ScaleFrame>
        </Timeline>
        <Timeline ActionTag="2070003754" Property="CColor">
          <ColorFrame FrameIndex="3" Alpha="255">
            <EasingData Type="0" />
            <Color A="255" R="255" G="255" B="255" />
          </ColorFrame>
        </Timeline>
        <Timeline ActionTag="948767101" Property="Position">
          <PointFrame FrameIndex="1" X="-0.1466" Y="-0.4120">
            <EasingData Type="0" />
          </PointFrame>
        </Timeline>
        <Timeline ActionTag="948767101" Property="Scale">
          <ScaleFrame FrameIndex="1" X="1.5000" Y="1.5000">
            <EasingData Type="0" />
          </ScaleFrame>
        </Timeline>
        <Timeline ActionTag="948767101" Property="RotationSkew">
          <ScaleFrame FrameIndex="1" X="0.0000" Y="0.0000">
            <EasingData Type="0" />
          </ScaleFrame>
        </Timeline>
        <Timeline ActionTag="1338896507" Property="Position">
          <PointFrame FrameIndex="1" X="25.3201" Y="24.7748">
            <EasingData Type="0" />
          </PointFrame>
        </Timeline>
        <Timeline ActionTag="1338896507" Property="Scale">
          <ScaleFrame FrameIndex="1" X="0.7500" Y="0.7500">
            <EasingData Type="0" />
          </ScaleFrame>
          <ScaleFrame FrameIndex="10" X="0.9000" Y="0.9000">
            <EasingData Type="0" />
          </ScaleFrame>
        </Timeline>
        <Timeline ActionTag="1338896507" Property="RotationSkew">
          <ScaleFrame FrameIndex="1" X="0.0000" Y="0.0000">
            <EasingData Type="0" />
          </ScaleFrame>
        </Timeline>
        <Timeline ActionTag="-2127381670" Property="Position">
          <PointFrame FrameIndex="3" X="24.2039" Y="64.2850">
            <EasingData Type="0" />
          </PointFrame>
        </Timeline>
        <Timeline ActionTag="-2127381670" Property="Scale">
          <ScaleFrame FrameIndex="3" X="0.5000" Y="0.5000">
            <EasingData Type="0" />
          </ScaleFrame>
        </Timeline>
        <Timeline ActionTag="-2127381670" Property="CColor">
          <ColorFrame FrameIndex="3" Alpha="255">
            <EasingData Type="0" />
            <Color A="255" R="255" G="255" B="255" />
          </ColorFrame>
        </Timeline>
        <Timeline ActionTag="-1036126294" Property="Position">
          <PointFrame FrameIndex="1" X="175.6999" Y="-1.8110">
            <EasingData Type="0" />
          </PointFrame>
        </Timeline>
        <Timeline ActionTag="-1036126294" Property="Scale">
          <ScaleFrame FrameIndex="1" X="1.5000" Y="1.5000">
            <EasingData Type="0" />
          </ScaleFrame>
        </Timeline>
        <Timeline ActionTag="-1036126294" Property="RotationSkew">
          <ScaleFrame FrameIndex="1" X="0.0000" Y="0.0000">
            <EasingData Type="0" />
          </ScaleFrame>
        </Timeline>
      </Animation>
      <AnimationList>
        <AnimationInfo Name="transport" StartIndex="1" EndIndex="10">
          <RenderColor A="150" R="0" G="0" B="128" />
        </AnimationInfo>
      </AnimationList>
      <ObjectData Name="Node" CustomClassName="Transport" Tag="251" ctype="GameNodeObjectData">
        <Size />
        <Children>
          <AbstractNodeData Name="circle1" ActionTag="948767101" Tag="256" IconVisible="False" LeftMargin="-25.1466" RightMargin="-24.8534" TopMargin="-24.5880" BottomMargin="-25.4120" ctype="SpriteObjectData">
            <Size X="50.0000" Y="50.0000" />
            <Children>
              <AbstractNodeData Name="star1" ActionTag="539000274" Tag="255" IconVisible="False" LeftMargin="-5.1980" RightMargin="-4.8020" TopMargin="-4.3669" BottomMargin="-5.6331" ctype="SpriteObjectData">
                <Size X="60.0000" Y="60.0000" />
                <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                <Position X="24.8020" Y="24.3669" />
                <Scale ScaleX="0.9000" ScaleY="0.9000" />
                <CColor A="255" R="255" G="255" B="255" />
                <PrePosition X="0.4960" Y="0.4873" />
                <PreSize />
                <FileData Type="Normal" Path="asset/explode1.png" Plist="" />
                <BlendFunc Src="1" Dst="771" />
              </AbstractNodeData>
              <AbstractNodeData Name="Button1" ActionTag="-1573295237" Tag="261" IconVisible="False" LeftMargin="-0.7330" RightMargin="-0.2670" TopMargin="64.1734" BottomMargin="-39.1734" TouchEnable="True" FontSize="14" Scale9Enable="True" LeftEage="15" RightEage="15" TopEage="8" BottomEage="8" Scale9OriginX="15" Scale9OriginY="8" Scale9Width="21" Scale9Height="9" OutlineSize="1" ShadowOffsetX="2" ShadowOffsetY="-2" ctype="ButtonObjectData">
                <Size X="51.0000" Y="25.0000" />
                <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                <Position X="24.7670" Y="-26.6734" />
                <Scale ScaleX="1.0000" ScaleY="1.0000" />
                <CColor A="255" R="255" G="255" B="255" />
                <PrePosition X="0.4953" Y="-0.5335" />
                <PreSize />
                <TextColor A="255" R="65" G="65" B="70" />
                <DisabledFileData Type="Default" Path="Default/Button_Disable.png" Plist="" />
                <PressedFileData Type="Normal" Path="asset/okButton.png" Plist="" />
                <NormalFileData Type="Normal" Path="asset/okButton.png" Plist="" />
                <OutlineColor A="255" R="255" G="0" B="0" />
                <ShadowColor A="255" R="110" G="110" B="110" />
              </AbstractNodeData>
              <AbstractNodeData Name="Label1" ActionTag="2070003754" Tag="265" IconVisible="False" LeftMargin="-12.9810" RightMargin="-12.0190" TopMargin="-56.0377" BottomMargin="23.0377" LabelText="in" ctype="TextBMFontObjectData">
                <Size X="75.0000" Y="83.0000" />
                <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                <Position X="24.5190" Y="64.5377" />
                <Scale ScaleX="0.5000" ScaleY="0.5000" />
                <CColor A="255" R="255" G="255" B="255" />
                <PrePosition X="0.4904" Y="1.2908" />
                <PreSize />
                <LabelBMFontFile_CNB Type="Normal" Path="font01.fnt" Plist="" />
              </AbstractNodeData>
            </Children>
            <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
            <Position X="-0.1466" Y="-0.4120" />
            <Scale ScaleX="1.5000" ScaleY="1.5000" />
            <CColor A="255" R="255" G="255" B="255" />
            <PrePosition />
            <PreSize />
            <FileData Type="Normal" Path="asset/transport.png" Plist="" />
            <BlendFunc Src="1" Dst="771" />
          </AbstractNodeData>
          <AbstractNodeData Name="circle2" ActionTag="-1036126294" Tag="258" IconVisible="False" LeftMargin="150.6999" RightMargin="-200.6999" TopMargin="-23.1890" BottomMargin="-26.8110" ctype="SpriteObjectData">
            <Size X="50.0000" Y="50.0000" />
            <Children>
              <AbstractNodeData Name="star2" ActionTag="1338896507" Tag="259" IconVisible="False" LeftMargin="-4.6799" RightMargin="-5.3201" TopMargin="-4.7748" BottomMargin="-5.2252" ctype="SpriteObjectData">
                <Size X="60.0000" Y="60.0000" />
                <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                <Position X="25.3201" Y="24.7748" />
                <Scale ScaleX="0.7500" ScaleY="0.7500" />
                <CColor A="255" R="255" G="255" B="255" />
                <PrePosition X="0.5064" Y="0.4955" />
                <PreSize />
                <FileData Type="Normal" Path="asset/explode1.png" Plist="" />
                <BlendFunc Src="1" Dst="771" />
              </AbstractNodeData>
              <AbstractNodeData Name="Button2" ActionTag="310413994" Tag="263" IconVisible="False" LeftMargin="0.4952" RightMargin="-1.4952" TopMargin="61.7470" BottomMargin="-36.7470" TouchEnable="True" FontSize="14" Scale9Enable="True" LeftEage="15" RightEage="15" TopEage="8" BottomEage="8" Scale9OriginX="15" Scale9OriginY="8" Scale9Width="21" Scale9Height="9" OutlineSize="1" ShadowOffsetX="2" ShadowOffsetY="-2" ctype="ButtonObjectData">
                <Size X="51.0000" Y="25.0000" />
                <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                <Position X="25.9952" Y="-24.2470" />
                <Scale ScaleX="1.0000" ScaleY="1.0000" />
                <CColor A="255" R="255" G="255" B="255" />
                <PrePosition X="0.5199" Y="-0.4849" />
                <PreSize />
                <TextColor A="255" R="65" G="65" B="70" />
                <DisabledFileData Type="Default" Path="Default/Button_Disable.png" Plist="" />
                <PressedFileData Type="Normal" Path="asset/okButton.png" Plist="" />
                <NormalFileData Type="Normal" Path="asset/okButton.png" Plist="" />
                <OutlineColor A="255" R="255" G="0" B="0" />
                <ShadowColor A="255" R="110" G="110" B="110" />
              </AbstractNodeData>
              <AbstractNodeData Name="Label2" ActionTag="-2127381670" Tag="266" IconVisible="False" LeftMargin="-39.7961" RightMargin="-38.2039" TopMargin="-55.7850" BottomMargin="22.7850" LabelText="out" ctype="TextBMFontObjectData">
                <Size X="128.0000" Y="83.0000" />
                <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                <Position X="24.2039" Y="64.2850" />
                <Scale ScaleX="0.5000" ScaleY="0.5000" />
                <CColor A="255" R="255" G="255" B="255" />
                <PrePosition X="0.4841" Y="1.2857" />
                <PreSize />
                <LabelBMFontFile_CNB Type="Normal" Path="font01.fnt" Plist="" />
              </AbstractNodeData>
            </Children>
            <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
            <Position X="175.6999" Y="-1.8110" />
            <Scale ScaleX="1.5000" ScaleY="1.5000" />
            <CColor A="255" R="255" G="255" B="255" />
            <PrePosition />
            <PreSize />
            <FileData Type="Normal" Path="asset/transport.png" Plist="" />
            <BlendFunc Src="1" Dst="771" />
          </AbstractNodeData>
        </Children>
      </ObjectData>
    </Content>
  </Content>
</GameProjectFile>