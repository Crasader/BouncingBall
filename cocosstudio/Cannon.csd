<GameProjectFile>
  <PropertyGroup Type="Node" Name="Cannon" ID="6a80b1e9-3291-4910-b0d0-9a4956d7e994" Version="2.2.8.0" />
  <Content ctype="GameProjectContent">
    <Content>
      <Animation Duration="5" Speed="0.1667" ActivedAnimationName="Shoot">
        <Timeline ActionTag="-1721826314" Property="FileData">
          <TextureFrame FrameIndex="0" Tween="False">
            <TextureFile Type="Normal" Path="res/cannon1.png" Plist="" />
          </TextureFrame>
          <TextureFrame FrameIndex="1" Tween="False">
            <TextureFile Type="Normal" Path="res/cannon1.png" Plist="" />
          </TextureFrame>
          <TextureFrame FrameIndex="2" Tween="False">
            <TextureFile Type="Normal" Path="res/cannon2.png" Plist="" />
          </TextureFrame>
          <TextureFrame FrameIndex="3" Tween="False">
            <TextureFile Type="Normal" Path="res/cannon3.png" Plist="" />
          </TextureFrame>
          <TextureFrame FrameIndex="4" Tween="False">
            <TextureFile Type="Normal" Path="res/cannon4.png" Plist="" />
          </TextureFrame>
          <TextureFrame FrameIndex="5" Tween="False">
            <TextureFile Type="Normal" Path="res/cannon1.png" Plist="" />
          </TextureFrame>
        </Timeline>
      </Animation>
      <AnimationList>
        <AnimationInfo Name="Shoot" StartIndex="1" EndIndex="6">
          <RenderColor A="255" R="220" G="220" B="220" />
        </AnimationInfo>
      </AnimationList>
      <ObjectData Name="Node" CustomClassName="Cannon" Tag="85" ctype="GameNodeObjectData">
        <Size />
        <Children>
          <AbstractNodeData Name="cannon" ActionTag="-1721826314" Tag="86" IconVisible="False" PositionPercentXEnabled="True" PositionPercentYEnabled="True" LeftMargin="-90.0000" RightMargin="-90.0000" TopMargin="-156.0000" BottomMargin="-44.0000" ctype="SpriteObjectData">
            <Size X="180.0000" Y="200.0000" />
            <Children>
              <AbstractNodeData Name="Aimshot_1" ActionTag="1382135629" Tag="62" Alpha="127" IconVisible="False" PositionPercentXEnabled="True" LeftMargin="65.0000" RightMargin="65.0000" TopMargin="29.9339" BottomMargin="120.0661" ctype="SpriteObjectData">
                <Size X="50.0000" Y="50.0000" />
                <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                <Position X="90.0000" Y="145.0661" />
                <Scale ScaleX="1.0000" ScaleY="1.0000" />
                <CColor A="255" R="255" G="255" B="255" />
                <PrePosition X="0.5000" Y="0.7253" />
                <PreSize X="0.2778" Y="0.2500" />
                <FileData Type="Normal" Path="res/Aimshot.png" Plist="" />
                <BlendFunc Src="1" Dst="771" />
              </AbstractNodeData>
              <AbstractNodeData Name="Aimshot_2" ActionTag="39285392" Tag="63" Alpha="127" IconVisible="False" PositionPercentXEnabled="True" LeftMargin="65.0000" RightMargin="65.0000" TopMargin="-20.0659" BottomMargin="170.0659" ctype="SpriteObjectData">
                <Size X="50.0000" Y="50.0000" />
                <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                <Position X="90.0000" Y="195.0659" />
                <Scale ScaleX="1.0000" ScaleY="1.0000" />
                <CColor A="255" R="255" G="255" B="255" />
                <PrePosition X="0.5000" Y="0.9753" />
                <PreSize X="0.2778" Y="0.2500" />
                <FileData Type="Normal" Path="res/Aimshot.png" Plist="" />
                <BlendFunc Src="1" Dst="771" />
              </AbstractNodeData>
              <AbstractNodeData Name="Aimshot_3" ActionTag="1923387436" Tag="64" Alpha="127" IconVisible="False" PositionPercentXEnabled="True" LeftMargin="65.0000" RightMargin="65.0000" TopMargin="-70.0661" BottomMargin="220.0661" ctype="SpriteObjectData">
                <Size X="50.0000" Y="50.0000" />
                <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                <Position X="90.0000" Y="245.0661" />
                <Scale ScaleX="1.0000" ScaleY="1.0000" />
                <CColor A="255" R="255" G="255" B="255" />
                <PrePosition X="0.5000" Y="1.2253" />
                <PreSize X="0.2778" Y="0.2500" />
                <FileData Type="Normal" Path="res/Aimshot.png" Plist="" />
                <BlendFunc Src="1" Dst="771" />
              </AbstractNodeData>
              <AbstractNodeData Name="Aimshot_4" ActionTag="827292404" Tag="65" Alpha="127" IconVisible="False" PositionPercentXEnabled="True" LeftMargin="65.0000" RightMargin="65.0000" TopMargin="-120.0659" BottomMargin="270.0659" ctype="SpriteObjectData">
                <Size X="50.0000" Y="50.0000" />
                <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                <Position X="90.0000" Y="295.0659" />
                <Scale ScaleX="1.0000" ScaleY="1.0000" />
                <CColor A="255" R="255" G="255" B="255" />
                <PrePosition X="0.5000" Y="1.4753" />
                <PreSize X="0.2778" Y="0.2500" />
                <FileData Type="Normal" Path="res/Aimshot.png" Plist="" />
                <BlendFunc Src="1" Dst="771" />
              </AbstractNodeData>
              <AbstractNodeData Name="Aimshot_5" ActionTag="-1319966423" Tag="66" Alpha="127" IconVisible="False" PositionPercentXEnabled="True" LeftMargin="65.0000" RightMargin="65.0000" TopMargin="-170.0000" BottomMargin="320.0000" ctype="SpriteObjectData">
                <Size X="50.0000" Y="50.0000" />
                <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                <Position X="90.0000" Y="345.0000" />
                <Scale ScaleX="1.0000" ScaleY="1.0000" />
                <CColor A="255" R="255" G="255" B="255" />
                <PrePosition X="0.5000" Y="1.7250" />
                <PreSize X="0.2778" Y="0.2500" />
                <FileData Type="Normal" Path="res/Aimshot.png" Plist="" />
                <BlendFunc Src="1" Dst="771" />
              </AbstractNodeData>
              <AbstractNodeData Name="Aimshot_6" ActionTag="-2077752619" Tag="67" Alpha="127" IconVisible="False" PositionPercentXEnabled="True" LeftMargin="65.0000" RightMargin="65.0000" TopMargin="-220.0000" BottomMargin="370.0000" ctype="SpriteObjectData">
                <Size X="50.0000" Y="50.0000" />
                <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                <Position X="90.0000" Y="395.0000" />
                <Scale ScaleX="1.0000" ScaleY="1.0000" />
                <CColor A="255" R="255" G="255" B="255" />
                <PrePosition X="0.5000" Y="1.9750" />
                <PreSize X="0.2778" Y="0.2500" />
                <FileData Type="Normal" Path="res/Aimshot.png" Plist="" />
                <BlendFunc Src="1" Dst="771" />
              </AbstractNodeData>
            </Children>
            <AnchorPoint ScaleX="0.5000" ScaleY="0.2200" />
            <Position />
            <Scale ScaleX="1.0000" ScaleY="1.0000" />
            <CColor A="255" R="255" G="255" B="255" />
            <PrePosition />
            <PreSize X="1.3433" Y="3.7736" />
            <FileData Type="Normal" Path="res/cannon1.png" Plist="" />
            <BlendFunc Src="1" Dst="771" />
          </AbstractNodeData>
        </Children>
      </ObjectData>
    </Content>
  </Content>
</GameProjectFile>