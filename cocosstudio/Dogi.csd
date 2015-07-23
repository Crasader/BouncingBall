<GameProjectFile>
  <PropertyGroup Type="Node" Name="Dogi" ID="04dc5b1b-488b-467b-929f-bea08d92e358" Version="2.2.8.0" />
  <Content ctype="GameProjectContent">
    <Content>
      <Animation Duration="5" Speed="0.1667" ActivedAnimationName="Shoot">
        <Timeline ActionTag="-450043310" Property="Position">
          <PointFrame FrameIndex="0" X="0.0000" Y="0.0000">
            <EasingData Type="0" />
          </PointFrame>
          <PointFrame FrameIndex="1" X="0.0000" Y="0.0000">
            <EasingData Type="0" />
          </PointFrame>
          <PointFrame FrameIndex="2" X="0.0000" Y="0.0000">
            <EasingData Type="0" />
          </PointFrame>
          <PointFrame FrameIndex="3" X="0.0000" Y="0.0000">
            <EasingData Type="0" />
          </PointFrame>
          <PointFrame FrameIndex="5" X="0.0000" Y="0.0000">
            <EasingData Type="0" />
          </PointFrame>
        </Timeline>
        <Timeline ActionTag="-450043310" Property="Scale">
          <ScaleFrame FrameIndex="0" X="1.0000" Y="1.0000">
            <EasingData Type="0" />
          </ScaleFrame>
          <ScaleFrame FrameIndex="5" X="1.0000" Y="1.0000">
            <EasingData Type="0" />
          </ScaleFrame>
        </Timeline>
        <Timeline ActionTag="-450043310" Property="RotationSkew">
          <ScaleFrame FrameIndex="0" X="0.0000" Y="0.0000">
            <EasingData Type="0" />
          </ScaleFrame>
          <ScaleFrame FrameIndex="5" X="0.0000" Y="0.0000">
            <EasingData Type="0" />
          </ScaleFrame>
        </Timeline>
        <Timeline ActionTag="-450043310" Property="FileData">
          <TextureFrame FrameIndex="1" Tween="False">
            <TextureFile Type="Normal" Path="res/dogi1.png" Plist="" />
          </TextureFrame>
          <TextureFrame FrameIndex="2" Tween="False">
            <TextureFile Type="Normal" Path="res/dogi2.png" Plist="" />
          </TextureFrame>
          <TextureFrame FrameIndex="3" Tween="False">
            <TextureFile Type="Normal" Path="res/dogi3.png" Plist="" />
          </TextureFrame>
          <TextureFrame FrameIndex="4" Tween="False">
            <TextureFile Type="Normal" Path="res/dogi1.png" Plist="" />
          </TextureFrame>
          <TextureFrame FrameIndex="5" Tween="False">
            <TextureFile Type="Normal" Path="res/dogi1.png" Plist="" />
          </TextureFrame>
        </Timeline>
      </Animation>
      <AnimationList>
        <AnimationInfo Name="Shoot" StartIndex="1" EndIndex="4">
          <RenderColor A="150" R="0" G="191" B="255" />
        </AnimationInfo>
      </AnimationList>
      <ObjectData Name="Node" CustomClassName="Dogi" Tag="244" ctype="GameNodeObjectData">
        <Size />
        <Children>
          <AbstractNodeData Name="dogi" ActionTag="-450043310" Tag="245" IconVisible="False" LeftMargin="-110.0000" RightMargin="-110.0000" TopMargin="-220.0000" ctype="SpriteObjectData">
            <Size X="220.0000" Y="220.0000" />
            <AnchorPoint ScaleX="0.5000" />
            <Position />
            <Scale ScaleX="1.0000" ScaleY="1.0000" />
            <CColor A="255" R="255" G="255" B="255" />
            <PrePosition />
            <PreSize />
            <FileData Type="Normal" Path="res/dogi1.png" Plist="" />
            <BlendFunc Src="1" Dst="771" />
          </AbstractNodeData>
        </Children>
      </ObjectData>
    </Content>
  </Content>
</GameProjectFile>